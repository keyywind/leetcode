class SolutionSub {
public:
    class Pair
    {
    public:
        int index, value, curMax;
        Pair(int index = 0, int value = 0) : index(index), value(value) { ; }
        inline static bool cmp(const Pair & first, const Pair & second)
        {
            if (first.value < second.value)
            {
                return true;
            }
            else if (first.value > second.value)
            {
                return false;
            }
            else
            {
                return (first.index < second.index);
            }
        }
    };
    static constexpr int MAX_SIZE = 100000;
    static vector <Pair> TABLE;
    static int tableSize;
    static void init(vector <int> & prices)
    {
        tableSize = prices.size();
        int i;
        for (i = 0; i < tableSize; ++i)
        {
            TABLE[i] = Pair(i, prices[i]);
        }
        sort(TABLE.begin(), TABLE.begin() + tableSize, SolutionSub::Pair::cmp);
        i = tableSize - 1;
        TABLE[i].curMax = TABLE[i].value;
        for (i = i - 1; i >= 0; --i)
        {
            TABLE[i].curMax = max(TABLE[i + 1].curMax, TABLE[i + 1].value);
        }
    }
    static int maximize_profit()
    {
        int i, j, k = tableSize - 1, maxProfit = 0, profit;
        for (i = 0; i < tableSize; ++i)
        {
            if (TABLE[i].value >= TABLE[i].curMax)
            {
                break;
            }
            for (j = k; j >= 0; j--)
            {
                profit = (TABLE[j].value - TABLE[i].value);
                if (maxProfit < profit)
                {
                    if (TABLE[i].index < TABLE[j].index)
                    {
                        maxProfit = profit;
                    }
                }
                else
                {
                    break;
                }
            }
        }
        return maxProfit;
    }
};
vector <SolutionSub::Pair> SolutionSub::TABLE(SolutionSub::MAX_SIZE);
int SolutionSub::tableSize;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        SolutionSub::init(prices);
        return SolutionSub::maximize_profit();
    }
};
