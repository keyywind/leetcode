/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class SolutionSub
{
public:
    static constexpr int MAX_NODES = 100;
    static int STRING[MAX_NODES];
    static int counter;
    static string format_path_string()
    {
        string result = "";
        int last = counter - 1;
        for (int i = 0; i < last; ++i)
            result += (to_string(STRING[i]) + "->");
        return result + to_string(STRING[last]);
    }
    static void find_paths(vector <string> & pathList, TreeNode * node)
    {
        STRING[counter++] = node->val;
        if ((node->left) && (node->right))
        {
            find_paths(pathList, node->left);
            find_paths(pathList, node->right);
        }
        else if (node->left)
        {
            find_paths(pathList, node->left);
        }
        else if (node->right)
        {
            find_paths(pathList, node->right);
        }
        else
        {
            pathList.push_back(format_path_string());
        }
        counter--;
    }
};
int SolutionSub::STRING[SolutionSub::MAX_NODES];
int SolutionSub::counter = 0;
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector <string> result;
        SolutionSub::find_paths(result, root);
        return result;
    }
};
