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
    static void preorder(vector <int> & traversal, int & index, TreeNode * node)
    {
        if (node)
        {
            traversal[index++] = node->val;
            preorder(traversal, index, node->left);
            preorder(traversal, index, node->right);
        }
    }
};
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        #define MAX_SIZE 100
        vector <int> traversal(MAX_SIZE);
        int index = 0;
        SolutionSub::preorder(traversal, index, root);
        traversal.erase(traversal.begin() + index, traversal.end());
        return traversal;
    }
};
