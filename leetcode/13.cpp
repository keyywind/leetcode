class Solution {
public:
    int romanToInt(string s) {
        s += 'P';
        int i, j, strlen = s.length(), result = 0;
        char temp;
        for (i = 0; i < strlen; )
        {
            temp = s[i];
            if (temp == 'I')
            {
                j = i + 1;
                if (s[j] == 'V')
                {
                    result += 4;
                    i += 2;
                }
                else if (s[j] == 'X')
                {
                    result += 9;
                    i += 2;
                }
                else
                {
                    result += 1;
                    i += 1;
                }
            }
            else if (temp == 'X')
            {
                j = i + 1;
                if (s[j] == 'L')
                {
                    result += 40;
                    i += 2;
                }
                else if (s[j] == 'C')
                {
                    result += 90;
                    i += 2;
                }
                else
                {
                    result += 10;
                    i += 1;
                }
            }
            else if (temp == 'C')
            {
                j = i + 1;
                if (s[j] == 'D')
                {
                    result += 400;
                    i += 2;
                }
                else if (s[j] == 'M')
                {
                    result += 900;
                    i += 2;
                }
                else
                {
                    result += 100;
                    i += 1;
                }
            }
            else
            {
                switch (temp)
                {
                case 'V':
                    result += 5;
                    break;
                case 'L':
                    result += 50;
                    break;
                case 'D':
                    result += 500;
                    break;
                case 'M':
                    result += 1000;
                    break;
                default:
                    result += 0;
                }
                i += 1;
            }
        }
        return result;
    }
};
