#define MAX_BITS 64
#define MAX_ROWS  2
typedef unsigned long long int UINT64;
class ConstArray
{
public:
    UINT64 table[MAX_ROWS][MAX_BITS];
    constexpr ConstArray() : table()
    {
        for (UINT64 i = 0ULL, j = 0ULL; i < MAX_ROWS; ++i)
        {
            for (j = 0ULL; j < MAX_BITS; ++j)
            {
                table[i][j] = 1ULL << j;
            }
        }
    }
    const inline UINT64 at(UINT64 row, UINT64 col) const
    {
        return table[row][col];
    }
};
constexpr ConstArray maskTable = ConstArray();
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //initialize_mask_table();
        UINT64 strLen     = s.length(),
               maskUpper  = 0ULL,
               maskLower  = 0ULL,
               counter    = 0ULL,
               maxCounter = 0ULL,
               maskTemp;
        for (UINT64 i = 0ULL, j; i < strLen; ++i)
        {
            for (j = i; j < strLen; ++j)
            {
                if (s[j] < 64ULL)
                {
                    maskTemp = maskTable.at(0ULL, s[j]);//[0ULL][s[j]];
                    if (maskLower & maskTemp)
                    {
                        maskLower  = 0ULL;
                        maskUpper  = 0ULL;
                        maxCounter = ((maxCounter < counter) ? counter : maxCounter);
                        counter    = 0ULL;
                        break;
                    }
                    else
                    {
                        maskLower |= maskTemp;
                        counter++;
                    }
                }
                else
                {
                    maskTemp = maskTable.at(1ULL, s[j] - 64ULL); //[1ULL][s[j] - 64ULL];
                    if (maskUpper & maskTemp)
                    {
                        maskLower  = 0ULL;
                        maskUpper  = 0ULL;
                        maxCounter = ((maxCounter < counter) ? counter : maxCounter);
                        counter    = 0ULL;
                        break;
                    }
                    else
                    {
                        maskUpper |= maskTemp;
                        counter++;
                    }
                }
            }
        }
        return ((maxCounter < counter) ? counter : maxCounter);
    }
};
