class SolutionSub
{
public:
    static int find_major(vector <int> & nums)
    {
        vector <pair<int, int>> occList;
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
        {
            bool unfound = true;
            for (vector<pair<int, int>>::iterator it2 = occList.begin(); it2 != occList.end(); it2++)
            {
                if (*it == it2->first)
                {
                    it2->second++;
                    unfound = false;
                    break;
                }
            }
            if (unfound)
            {
                occList.push_back(make_pair(*it, 1));
            }
        }
        pair<int, int> maximum = make_pair(-1, -1);
        for (vector<pair<int, int>>::iterator it = occList.begin(); it != occList.end(); it++)
        {
            if (it->second > maximum.second)
            {
                maximum = *it;
            }
        }
        return maximum.first;
    }
};
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return SolutionSub::find_major(nums);
    }
};
