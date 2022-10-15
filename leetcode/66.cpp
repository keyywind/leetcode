class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector <int> result;
        int i, vecSize = digits.size(), carry = 1, sum;
        for (i = vecSize - 1; i >= 0; --i)
        {
            sum = digits[i] + carry;
            carry = sum / 10;
            result.insert(result.begin(), sum % 10);
        }
        if (carry)
        {
            result.insert(result.begin(), carry);
        }
        return result;
    }
};
