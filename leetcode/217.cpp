class SolutionSub
{
public:
    static bool contains_duplicate(vector <int> & nums)
    {
        set <int> record;
        for (vector<int>::iterator it = nums.begin(), end = nums.end(); it != end; it++)
        {
            if (record.find(*it) != record.end())
            {
                return true;
            }
            else
            {
                record.insert(*it);
            }
        }
        return false;
    }
};
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return SolutionSub::contains_duplicate(nums);
    }
};
