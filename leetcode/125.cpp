class SolutionSub
{
public:
    static constexpr int lowerShift = ('a' - 'A');
    static string format_string(const string & str)
    {
        string resultStr = "";
        int i, strlen = str.length();
        char chr;
        for (i = 0; i < strlen; ++i)
        {
            chr = str[i];
            if (('A' <= chr) && (chr <= 'Z'))
            {
                resultStr += ((char) (chr + lowerShift));
            }
            else if ((('0' <= chr) && (chr <= '9')) || (('a' <= chr) && (chr <= 'z')))
            {
                resultStr += chr;
            }
        }
        return resultStr;
    }
};
class Solution {
public:
    bool isPalindrome(string s) {
        s = SolutionSub::format_string(s);
        int i, strlen = s.length(), j = strlen - 1, k = strlen / 2;
        for (i = 0; i < k; ++i)
        {
            if (s[i] != s[j - i])
                return false;
        }
        return true;
    }
};
