class Solution {
public:
    string addBinary(string a, string b) {
        int lenA = a.length(),
            lenB = b.length(),
            i    = lenA - 1,
            j    = lenB - 1,
            charA, charB, sum, carry = 0;
        string addition = "";
        for (; ((i >= 0) && (j >= 0)); --i, --j)
        {
            charA = a[i] - '0';
            charB = b[j] - '0';
            sum   = charA + charB + carry;
            carry = sum / 2;
            addition = to_string(sum % 2) + addition;
        }
        for (; i >= 0; --i)
        {
            charA = a[i] - '0';
            sum   = charA + carry;
            carry = sum / 2;
            addition = to_string(sum % 2) + addition;
        }
        for (; j >= 0; --j)
        {
            charB = b[j] - '0';
            sum   = charB + carry;
            carry = sum / 2;
            addition = to_string(sum % 2) + addition;
        }
        if (carry)
        {
            addition = to_string(carry) + addition;
        }
        return addition;
    }
};
