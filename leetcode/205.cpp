class SolutionSub
{
public:
    static constexpr int MAX_DIGIT = 256;
    static char table[MAX_DIGIT];
    static inline void reset()
    {
        fill_n(table, MAX_DIGIT, 0);
    }
    static bool isomorphic(const string & str1, const string & str2)
    {
        reset();
        int i, j, strlen = str1.length();
        for (i = 0; i < strlen; ++i)
        {
            j = str1[i];
            if (table[j])
            {
                if (table[j] != str2[i])
                {
                    return false;
                }
            }
            else
            {
                table[j] = str2[i];
            }
        }
        return true;
    }
};
char SolutionSub::table[SolutionSub::MAX_DIGIT];
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        return (SolutionSub::isomorphic(s, t) && SolutionSub::isomorphic(t, s));
    }
};
