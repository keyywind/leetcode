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
    static int min_depth_rec(TreeNode * root)
    {
        if (root->left && root->right)
        {
            return 1 + min(
                min_depth_rec(root->left),
                min_depth_rec(root->right)
            );
        }
        else if (root->left)
        {
            return 1 + min_depth_rec(root->left);
        }
        else if (root->right)
        {
            return 1 + min_depth_rec(root->right);
        }
        else
        {
            return 1;
        }
    }
    static inline int min_depth(TreeNode * root)
    {
        if (root) return min_depth_rec(root);
        else return 0;
    }
};
class Solution {
public:
    int minDepth(TreeNode* root) {
        return SolutionSub::min_depth(root);
    }

};
