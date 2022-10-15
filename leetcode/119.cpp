class SolutionSub {
public:
    static constexpr int MAX_ROWS = 34;
    static int PASCAL[MAX_ROWS][MAX_ROWS];
    static bool UNSET;
    static int uncomputedRowIndex;
    static inline void reset()
    {
        if (UNSET) {
            for (int i = 0, j; i < MAX_ROWS; ++i)
            {
                for (j = 0; j < MAX_ROWS; ++j)
                {
                    PASCAL[i][j] = 1;
                }
            }
            UNSET = false;
        }
    }
};
bool SolutionSub::UNSET = true;
int SolutionSub::uncomputedRowIndex = 2;
int SolutionSub::PASCAL[SolutionSub::MAX_ROWS][SolutionSub::MAX_ROWS];
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        SolutionSub::reset();
        int i, j;
        for (i = SolutionSub::uncomputedRowIndex; i <= rowIndex; ++i)
        {
            SolutionSub::uncomputedRowIndex = max(SolutionSub::uncomputedRowIndex, rowIndex + 1);
            for (j = 1; j < i; ++j)
            {
                SolutionSub::PASCAL[i][j] = (
                    SolutionSub::PASCAL[i - 1][j] +
                    SolutionSub::PASCAL[i - 1][j - 1]
                );
            }
        }
        int * row = SolutionSub::PASCAL[rowIndex];
        return vector <int> (row, row + (rowIndex + 1));
    }
};
