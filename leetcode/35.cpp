class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int L = 0, R = nums.size() - 1, M;
        while (L <= R)
        {
            M = (L + R) / 2;
            if (nums[M] == target)
            {
                return M;
            }
            else if (nums[M] < target)
            {
                L = M + 1;
            }
            else
            {
                R = M - 1;
            }
        }
        return ((nums[M] < target) ? (M + 1) : (M));
    }
};
