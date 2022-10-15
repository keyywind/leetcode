class SolutionSub
{
public:
    static bool power_of_three(int number)
    {
        int remainder, quotient = number;
        while (quotient)
        {
            remainder = quotient % 3;
            quotient  = quotient / 3;
            if ((quotient) && (remainder))
                return false;
        }
        return (remainder == 1);
    }
};
class Solution {
public:
    bool isPowerOfThree(int n) {
        return SolutionSub::power_of_three(n);
    }
};
