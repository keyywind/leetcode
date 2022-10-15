class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        #define MAX_SIZE 200
        static int table[MAX_SIZE];
        int i = 0, j = 0, k = 0, l = m + n;
        while (j < m && k < n)
        {
            if (nums1[j] < nums2[k])
            {
                table[i++] = nums1[j++];
            }
            else
            {
                table[i++] = nums2[k++];
            }
        }
        while (j < m)
        {
            table[i++] = nums1[j++];
        }
        while (k < n)
        {
            table[i++] = nums2[k++];
        }
        for (i = 0; i < l; ++i)
        {
            nums1[i] = table[i];
        }
    }
};
