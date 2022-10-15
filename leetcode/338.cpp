class Solution {
public:
    vector<int> countBits(int n) {
        vector <int> result(n + 1);
        result[0] = 0;
        if (n)
        {
            result[1] = 1;
            int i, j, k;
            for (i = 2; i <= n; i *= 2)
            {
                k = 2 * i;
                for (j = i; ((j < k) && (j <= n)); ++j)
                {
                    result[j] = result[j % i] + 1;
                }
            }
        }
        return result;
    }
};
