class Solution {
public:
    int hammingWeight(uint32_t n) {
        constexpr uint32_t mask = 1UL;
        int result = 0;
        for (; n; n = n >> 1)
        {
            if (n & mask)
            {
                result++;
            }
        }
        return result;
    }
};
