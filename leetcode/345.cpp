class SolutionSub
{
public:
    static constexpr int MAX_LEN = 300000;
    static int INDEX[MAX_LEN];
    static int counter;
    static inline bool is_vowel(const char & character)
    {
        switch (character)
        {
            case 'a':
                return true;
            case 'e':
                return true;
            case 'i':
                return true;
            case 'o':
                return true;
            case 'u':
                return true;
            case 'A':
                return true;
            case 'E':
                return true;
            case 'I':
                return true;
            case 'O':
                return true;
            case 'U':
                return true;
            default:
                return false;
        }
    }
    static void find_vowels(const string & targetStr)
    {
        counter = 0;
        int i, len = targetStr.length();
        for (i = 0; i < len; ++i)
            if (is_vowel(targetStr[i]))
                INDEX[counter++] = i;
    }
    static void reverse_vowels(string & targetStr)
    {
        int i, half = counter / 2, tail = counter - 1;
        for (i = 0; i < half; ++i)
            swap(targetStr[INDEX[i]], targetStr[INDEX[tail - i]]);
    }
};
int SolutionSub::INDEX[SolutionSub::MAX_LEN];
int SolutionSub::counter = 0;
class Solution {
public:
    string reverseVowels(string s) {
        string finalStr = s;
        SolutionSub::find_vowels(finalStr);
        SolutionSub::reverse_vowels(finalStr);
        return finalStr;
    }
};
