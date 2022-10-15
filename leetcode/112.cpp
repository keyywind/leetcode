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
    static bool match;
    static void find_match_rec(TreeNode * root, int accum, int & target)
    {
        if (match) return;
        accum += root->val;
        if (root->left && root->right)
        {
            find_match_rec(root->left, accum, target);
            if (match) return;
            find_match_rec(root->right, accum, target);
        }
        else if (root->left)
        {
            find_match_rec(root->left, accum, target);
        }
        else if (root->right)
        {
            find_match_rec(root->right, accum, target);
        }
        else
        {
            if (accum == target)
            {
                match = true;
            }
        }
    }
    static inline bool is_match(TreeNode * root, int & target)
    {
        if (root)
        {
            match = false;
            find_match_rec(root, 0, target);
            return match;
        }
        else
        {
            return false;
        }
    }
};
bool SolutionSub::match = false;
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return SolutionSub::is_match(root, targetSum);
    }
};
