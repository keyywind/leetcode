class Solution {
public:
    bool isValid(string s) {
        #define MAX_STACK_SIZE 10001
        int i, strlen = s.length(), counter = 1;
        char temp, prev, stack[MAX_STACK_SIZE];
        for (i = 0; i < strlen; ++i)
        {
            temp = s[i];  prev = stack[counter - 1];
            if ((temp == '(') || (temp == '[') || (temp == '{'))
            {
                stack[counter++] = temp;
            }
            else if (temp == ')')
            {
                if (prev == '(')
                {
                    counter -= 1;
                }
                else
                {
                    return false;
                }
            }
            else if (temp == ']')
            {
                if (prev == '[')
                {
                    counter -= 1;
                }
                else
                {
                    return false;
                }
            }
            else if (temp == '}')
            {
                if (prev == '{')
                {
                    counter -= 1;
                }
                else
                {
                    return false;
                }
            }
        }
        return (counter == 1);
    }
};
