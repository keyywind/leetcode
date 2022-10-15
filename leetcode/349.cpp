class SolutionSub
{
public:
    static constexpr int MAX_LEN = 1000;
    static int ARRAY[MAX_LEN];
    static inline void reset()
    {
        fill_n(ARRAY, MAX_LEN, 0);
    }
    static void set_occurrence(const vector <int> & array)
    {
        reset();
        int i, len = array.size();
        for (i = 0; i < len; ++i)
            ARRAY[array[i]] = 1;
    }
    static void get_intersection(vector <int> & intersection, const vector <int> & array)
    {
        int i, j, len = array.size();
        for (i = 0; i < len; ++i)
        {
            j = array[i];
            if (ARRAY[j])
            {
                intersection.push_back(j);
                ARRAY[j] = 0;
            }
        }
    }
};
int SolutionSub::ARRAY[SolutionSub::MAX_LEN];
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector <int> _intersection;
        SolutionSub::set_occurrence(nums1);
        SolutionSub::get_intersection(_intersection, nums2);
        return _intersection;
    }
};
