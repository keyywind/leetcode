/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class SolutionSub
{
public:
    static constexpr int MAX_NODES = 100000;
    static char ARRAY[MAX_NODES];
    static int counter;
    static bool is_palindrome(ListNode * head)
    {
        counter = 0;
        for (ListNode * temp = head; temp; temp = temp->next)
        {
            ARRAY[counter++] = temp->val;
        }
        for (int i = 0, half = counter / 2, last = counter - 1; i < half; ++i)
        {
            if (ARRAY[i] != ARRAY[last - i])
                return false;
        }
        return true;
    }
};
char SolutionSub::ARRAY[SolutionSub::MAX_NODES];
int  SolutionSub::counter = 0;
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        return SolutionSub::is_palindrome(head);
    }
};
