class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = 0, vecSize = nums.size();
        while (true)
        {
            for (; ((i < vecSize) && (nums[i] != val)); ++i);
            for (j = i + 1; ((j < vecSize) && (nums[j] == val)); ++j);
            if ((i < vecSize) && (j < vecSize))
            {
                nums[i] = nums[i] ^ nums[j];
                nums[j] = nums[i] ^ nums[j];
                nums[i] = nums[i] ^ nums[j];
            }
            else
            {
                break;
            }
        }
        for (i = 0; i < vecSize; ++i)
        {
            if (nums[i] == val)
                return i;
        }
        return vecSize;
    }
};
