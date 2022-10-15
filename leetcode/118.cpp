class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector <vector<int>> pascal(1, vector<int>(1, 1));
        int i, j;
        for (i = 2; i <= numRows; ++i)
            pascal.push_back(vector<int>(i, 1));
        for (i = 2; i < numRows; ++i)
        {
            for (j = 1; j < i; ++j)
            {
                pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
            }
        }
        return pascal;
    }
};
