class SolutionSub
{
public:
    static bool contains_duplicate(vector <int> & nums, int k)
    {
        unordered_map <int, int> numset;
        for (int i = 0, size = nums.size(); i < size; ++i)
        {
            if (numset.find(nums[i]) == numset.end())
            {
                numset.insert(make_pair(nums[i], i));
            }
            else
            {
                if ((i - numset[nums[i]]) <= k)
                {
                    return true;
                }
                else
                {
                    numset[nums[i]] = i;
                }
            }
        }
        return false;
    }
};
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        return SolutionSub::contains_duplicate(nums, k);
    }
};
