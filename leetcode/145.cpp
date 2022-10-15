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
    static void postorder(vector <int> & traversal, int & index, TreeNode * node)
    {
        if (node)
        {
            postorder(traversal, index, node->left);
            postorder(traversal, index, node->right);
            traversal[index++] = node->val;
        }
    }
};
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        #define MAX_SIZE 100
        vector <int> traversal(MAX_SIZE);
        int index = 0;
        SolutionSub::postorder(traversal, index, root);
        traversal.erase(traversal.begin() + index, traversal.end());
        return traversal;
    }
};
