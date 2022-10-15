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
    static void insert_node_rec(TreeNode ** parentLink, TreeNode * child, int val)
    {
        if (child == nullptr)
        {
            *parentLink = new TreeNode(val);
        }
        else if (child->val <= val)
        {
            insert_node_rec(&(child->right), child->right, val);
        }
        else
        {
            insert_node_rec(&(child->left), child->left, val);
        }
    }
    static void insert_node(TreeNode * root, int val)
    {
        if (root->val <= val)
        {
            insert_node_rec(&(root->right), root->right, val);
        }
        else
        {
            insert_node_rec(&(root->left), root->left, val);
        }
    }
    static void insert_BST(TreeNode * root, vector <int> & nums, int low, int high)
    {
        if (low <= high) {
            int mid = (low + high) / 2;
            insert_node(root, nums[mid]);
            insert_BST(root, nums, low, mid - 1);
            insert_BST(root, nums, mid + 1, high);
        }
    }
};
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, mid = (low + high) / 2;
        TreeNode * root = new TreeNode(nums[mid]);
        SolutionSub::insert_BST(root, nums, low, mid - 1);
        SolutionSub::insert_BST(root, nums, mid + 1, high);
        return root;
    }
};
