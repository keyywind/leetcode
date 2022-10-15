class SolutionSub
{
public:
    static inline int indivisible(int & quotient, int number, int divider) /// returns remainder
    {
        quotient = number / divider;
        return number % divider;
    }
    static int divide(int number, int divider) /// returns quotient
    {
        int remainder, temp, quotient = number;
        for (;;)
        {
            remainder = indivisible(temp, quotient, divider);
            if (remainder)
                break;
            quotient = temp;
        }
        return quotient;
    }
    static bool is_ugly(int number)
    {
        if (number)
        {
            number = divide(number, 2);
            number = divide(number, 3);
            number = divide(number, 5);
        }
        return (number == 1);
    }
};
class Solution {
public:
    bool isUgly(int n) {
        return SolutionSub::is_ugly(n);
    }
};
