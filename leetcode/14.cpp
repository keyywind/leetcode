class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        #define MAX_STRS 200
        int i, j, minLen = 1000, numStr = strs.size();
        char temp, terminate = 0;  string prefix = "";
        for (i = 0; i < numStr; ++i)
            if (strs[i].length() < minLen)
                minLen = strs[i].length();
        for (i = 0; i < minLen; ++i)
        {
            temp = strs[0][i];
            for (j = 1; j < numStr; ++j)
            {
                if (temp != strs[j][i])
                {
                    terminate = 1;
                    break;
                }
            }
            if (terminate)
                break;
            prefix += temp;
        }
        return prefix;
    }
};
