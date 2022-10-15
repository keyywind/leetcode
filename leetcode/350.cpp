class SolutionSub
{
public:
    static constexpr int MAX_LEN = 1001;
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
            ARRAY[array[i]]++;
    }
    static void get_intersection(vector <int> & intersect, const vector <int> & array)
    {
        int i, j, len = array.size();
        for (i = 0; i < len; ++i)
        {
            j = array[i];
            if (ARRAY[j])
            {
                intersect.push_back(j);
                ARRAY[j]--;
            }
        }
    }
};
int SolutionSub::ARRAY[SolutionSub::MAX_LEN];
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector <int> intersection;
        SolutionSub::set_occurrence(nums1);
        SolutionSub::get_intersection(intersection, nums2);
        return intersection;
    }
};
