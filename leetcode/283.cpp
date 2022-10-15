class SolutionSub
{
public:
    static void move_zeros(vector <int> & nums)
    {
        int i, length = nums.size();
        for (i = length - 1; i >= 0; --i)
        {
            if (!nums[i])
                nums.erase(nums.begin() + i);
        }
        for (i = nums.size(); i < length; ++i)
            nums.push_back(0);
    }
};
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        SolutionSub::move_zeros(nums);
    }
};
