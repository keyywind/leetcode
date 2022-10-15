class SolutionSub
{
public:
    static constexpr int MAX_CHARS = 128;
    static int ARRAY1[MAX_CHARS],
               ARRAY2[MAX_CHARS];
    static inline void reset()
    {
        fill_n(ARRAY1, MAX_CHARS, 0);
        fill_n(ARRAY2, MAX_CHARS, 0);
    }
    static bool is_anagram(const string & s, const string & t)
    {
        int i, len1 = s.length();
        if (len1 != t.length())
            return false;
        reset();
        for (i = 0; i < len1; ++i)
        {
            ARRAY1[s[i]]++;
            ARRAY2[t[i]]++;
        }
        for (i = 0; i < MAX_CHARS; ++i)
            if (ARRAY1[i] != ARRAY2[i])
                return false;
        return true;
    }
};
int SolutionSub::ARRAY1[SolutionSub::MAX_CHARS];
int SolutionSub::ARRAY2[SolutionSub::MAX_CHARS];
class Solution {
public:
    bool isAnagram(string s, string t) {
        return SolutionSub::is_anagram(s, t);
    }
};
