class SolutionSub
{
public:
    static constexpr int MAX_SIZE = 10000;
    static char ARRAY[MAX_SIZE];
    static int arrSize;
    static inline void init(int arrSize)
    {
        SolutionSub::arrSize = arrSize;
        fill_n(ARRAY, MAX_SIZE, 0);
    }
    static int find_absent(vector <int> & nums)
    {
        init(nums.size());
        int i;
        for (i = 0; i < arrSize; ++i)
            ARRAY[nums[i]] = 1;
        for (i = 0; i <= arrSize; ++i)
            if (!ARRAY[i])
                return i;
        return 0;
    }
};
char SolutionSub::ARRAY[SolutionSub::MAX_SIZE];
int  SolutionSub::arrSize = 0;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        return SolutionSub::find_absent(nums);
    }
};
