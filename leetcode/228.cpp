class SolutionSub
{
public:
    static inline string format_string(int start, int end)
    {
        if (start == end)
        {
            return to_string(start);
        }
        else
        {
            return to_string(start) + "->" + to_string(end);
        }
    }
    static vector <string> find_ranges(vector <int> & nums)
    {
        int i, first, second, length = nums.size();
        long long int difference;
        vector <string> result;
        if (length)
        {
            first = second = nums[0];
            for (i = 1; i < length; ++i)
            {
                difference = nums[i];
                difference = difference - second;
                if (difference <= 1)
                    second = nums[i];
                else
                {
                    result.push_back(format_string(first, second));
                    first = second = nums[i];
                }
            }
            result.push_back(format_string(first, second));
        }
        return result;
    }
};
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        return SolutionSub::find_ranges(nums);
    }
};
