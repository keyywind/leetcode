class Solution {
public:
    int lengthOfLastWord(string s) {
        int i, strlen = s.length(), counter = 0;
        for (i = strlen - 1; i >= 0; i--)
        {
            if (s[i] == ' ')
            {
                if (counter)
                {
                    return counter;
                }
            }
            else
            {
                counter++;
            }
        }
        return counter;
    }
};
