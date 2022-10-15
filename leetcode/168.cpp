class SolutionSub
{
public:
    static constexpr int MAX_LEN = 31;
    static int table[MAX_LEN];
    static int counter;
    static inline void reset()
    {
        counter = 0;
    }
    static void convert_base26(int number)
    {
        if (number)
        {
            int remainder = number % 26,
                quotient  = number / 26;
            table[counter++] = remainder;
            convert_base26(quotient);
        }
    }
    static void remove_zero()
    {
        for (int i = 0, k = counter - 1; i < counter; ++i)
        {
            if (table[i] <= 0)
            {
                if (i < k)
                {
                    table[i]     += 26;
                    table[i + 1] -=  1;
                }
                else
                {
                    counter--;
                }
            }
        }
    }
    static string convert_string()
    {
        string result = "";
        while (counter)
        {
            result += ((char) (64 + table[--counter]));
        }
        return result;
    }
};
int SolutionSub::table[SolutionSub::MAX_LEN];
int SolutionSub::counter = 0;
class Solution {
public:
    string convertToTitle(int columnNumber) {
        SolutionSub::reset();
        SolutionSub::convert_base26(columnNumber);
        SolutionSub::remove_zero();
        return SolutionSub::convert_string();
    }
};
