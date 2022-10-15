constexpr int MAX_SIZE = 7;
class ConstArray
{
public:
    int weights[MAX_SIZE];
    constexpr ConstArray() : weights()
    {
        weights[0] = 1;
        for (int i = 1; i < MAX_SIZE; ++i)
        {
            weights[i] = weights[i - 1] * 26;
        }
    }
};
class SolutionSub
{
public:
    static constexpr char MIN_CHAR = 'A' - 1;
    static constexpr ConstArray table = ConstArray();
    static int string_to_int(const string & targetStr)
    {
        int i, total = 0, strlen = targetStr.length(), lenm1 = strlen - 1;
        for (i = 0; i < strlen; ++i)
        {
            total += ((targetStr[i] - MIN_CHAR) * table.weights[lenm1 - i]);
        }
        return total;
    }
};
class Solution {
public:
    int titleToNumber(string columnTitle) {
        return SolutionSub::string_to_int(columnTitle);
    }
};
