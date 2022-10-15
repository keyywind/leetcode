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
class SolutionSub {
public:
    static bool imbalance;
    inline static void reset()
    {
        imbalance = false;
    }
    static int balanced(TreeNode * root)
    {
        if (root)
        {
            if (imbalance) return 0;
            int left  = balanced(root->left);
            if (imbalance) return 0;
            int right = balanced(root->right);
            if (imbalance) return 0;
            if (abs(left - right) > 1) imbalance = true;
            return (1 + max(left, right));
        }
        else
        {
            return 0;
        }
    }
};
bool SolutionSub::imbalance = false;
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        SolutionSub::reset();
        SolutionSub::balanced(root);
        return (!SolutionSub::imbalance);
    }
};
