class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        int i, len = str.length(), lenHalf = len / 2;
        for (i = 0, len = len - 1; i < lenHalf; ++i)
        {
            if (str[i] != str[len - i])
                return false;
        }
        return true;
    }
};
