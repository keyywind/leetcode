class ConstArray
{
public:
    static constexpr int MAX_SIZE = 31;
    int ARRAY[MAX_SIZE];
    constexpr ConstArray() : ARRAY()
    {
        for (int i = 0; i < MAX_SIZE; ++i)
            ARRAY[i] = 1 << i;
    }
    constexpr int operator [] (int index) const
    {
        return ARRAY[index];
    }
};
class SolutionSub
{
public:
    static constexpr ConstArray masks = ConstArray();
    static bool is_two_power(int number)
    {
        if (number == 1)
            return true;
        if ((number % 2) || (!number))
            return false;
        for (int i = 0; i < ConstArray::MAX_SIZE; ++i)
        {
            if (number & masks[i])
                return (!(number ^ masks[i]));
        }
        return false;
    }
};
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return SolutionSub::is_two_power(n);
    }
};
