// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int L = 1, R = n;  long long int M;
        while (L < R)
        {
            M = L;
            M = (M + R) / 2;
            if (isBadVersion(M))
            {
                R = M;
            }
            else
            {
                L = M + 1;
            }
        }
        return R;
    }
};
