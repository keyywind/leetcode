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
    static constexpr int null = 200;
    static void preorderL(TreeNode * node, int * table, int & counter)
    {
        if (node == nullptr) {
            table[counter++] = null;
        }
        else {
            table[counter++] = node->val;
            preorderL(node->left, table, counter);
            preorderL(node->right, table, counter);
        }
    }
    static void preorderR(TreeNode * node, int * table, int & counter)
    {
        if (node == nullptr) {
            table[counter++] = null;
        }
        else {
            table[counter++] = node->val;
            preorderR(node->right, table, counter);
            preorderR(node->left, table, counter);
        }
    }
};
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        #define MAX_NODES 2000
        static int tablePre[MAX_NODES],
                   tablePos[MAX_NODES];
        int counterPre = 0,
            counterPos = 0;
        SolutionSub::preorderL(root, tablePre, counterPre);
        SolutionSub::preorderR(root, tablePos, counterPos);
        for (int i = 0; i < counterPre; ++i)
        {
            if (tablePre[i] != tablePos[i])
                return false;
        }
        return true;

    }
};
