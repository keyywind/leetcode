class SolutionSub
{
public:
    static bool indivisible(int number, int divisor)
    {
        int remainder = 0;
        while (number >= divisor)
        {
            remainder = number % divisor;
            number    = number / divisor;
            if (remainder)
                break;
        }
        return ((number == 1) && (remainder == 0));
    }
};
class Solution {
public:
    bool isPowerOfFour(int n) {
        return SolutionSub::indivisible(n, 4);
    }
};
