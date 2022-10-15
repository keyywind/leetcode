class ConstArray
{
public:
    static constexpr uint32_t BIT_COUNT = 32;
    uint32_t masks[BIT_COUNT];
    constexpr ConstArray() : masks()
    {
        for (uint32_t i = 0; i < BIT_COUNT; ++i)
        {
            masks[i] = (1UL << i);
        }
    }
    constexpr uint32_t operator [] (const uint32_t & index) const
    {
        return masks[index];
    }
};
class SolutionSub
{
public:
    static constexpr ConstArray masks = ConstArray();
    static uint32_t reverse(const uint32_t & value)
    {
        uint32_t result = 0, i, last = ConstArray::BIT_COUNT - 1;
        for (i = 0; i < ConstArray::BIT_COUNT; ++i)
        {
            if (value & masks[i])
            {
                result |= masks[last - i];
            }
        }
        return result;
    }
};
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        return SolutionSub::reverse(n);
    }
};
