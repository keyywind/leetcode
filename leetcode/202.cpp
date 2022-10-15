class SolutionSub
{
public:
    static inline int square(int value)
    {
        return value * value;
    }
    static int digit_square_sum(int number)
    {
        int total = 0;
        for (; number; number = number / 10)
        {
            total += square(number % 10);
        }
        return total;
    }
    static bool is_happy(int number)
    {
        unordered_set <int> numberSet;
        unordered_set<int>::iterator end = numberSet.end();
        while (number != 1)
        {
            if (numberSet.find(number) != end)
            {
                return false;
            }
            else
            {
                numberSet.insert(number);
            }
            number = digit_square_sum(number);
        }
        return true;
    }
};
class Solution {
public:
    bool isHappy(int n) {
        return SolutionSub::is_happy(n);
    }
};
