class SolutionSub
{
public:
    static int digits_sum(int number)
    {
        int result = 0, modulus;
        for (; number; number /= 10)
            result += (number % 10);
        return result;
    }
    static int add_digits(int number)
    {
        int next = number;
        for (; number / 10; number = next)
            next = digits_sum(number);
        return next;
    }
};
class Solution {
public:
    int addDigits(int num) {
        return SolutionSub::add_digits(num);
    }
};
