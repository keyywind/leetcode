class Solution {
public:
    void reverseString(vector<char>& s) {
        int i, j, len = s.size(), half = len / 2, tail = len - 1;
        for (i = 0; i < half; i++)
        {
            j = tail - i;
            s[i] = s[i] ^ s[j];
            s[j] = s[i] ^ s[j];
            s[i] = s[i] ^ s[j];
        }
    }
};
