class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        #define MAX_STACK_SIZE 30001
        int i, vecSize = nums.size(), counter = 1;
        for (i = 1; i < vecSize; ++i)
        {
            if (nums[counter - 1] != nums[i])
            {
                nums[counter++] = nums[i];
            }
        }
        return counter;
    }
};
