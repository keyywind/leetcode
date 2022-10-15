class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> result;
        for (int i = 0, j, t, length = nums.size(); i < length; ++i)
        {
            for (j = i + 1; j < length; ++j)
            {
                t = nums[i] + nums[j];
                if (t == target)
                {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
    }
};
