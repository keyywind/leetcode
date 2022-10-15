class SolutionSub
{
public:
    static constexpr int MAX_SIZE = 60001,
                         MAX_POSI = MAX_SIZE / 2;
    static short int   ARRAY[MAX_SIZE],
                     * POSITION;
    static inline void reset()
    {
        fill_n(ARRAY, MAX_SIZE, 0);
    }
    static int find_singular(const vector <int> & nums)
    {
        reset();
        int i, j, length = nums.size();
        for (i = 0; i < length; ++i)
        {
            j = nums[i];
            if (POSITION[j] < 2)
            {
                POSITION[j]++;
            }
        }
        for (i = 0; i < length; ++i)
        {
            j = nums[i];
            if (POSITION[j] == 1)
            {
                return j;
            }
        }
        return 0;
    }
};
short int   SolutionSub::ARRAY[MAX_SIZE],
          * SolutionSub::POSITION = &(SolutionSub::ARRAY[SolutionSub::MAX_POSI]);
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return SolutionSub::find_singular(nums);
    }
};
