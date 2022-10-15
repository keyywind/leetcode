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
    static inline ListNode * next(ListNode * node)
    {
        return ((node) ? (node->next) : (nullptr));
    }
    static ListNode * reverse_rec(ListNode * temp1, ListNode * temp2, ListNode * temp3)
    {
        if (temp2)
        {
            temp2->next = temp1;
            if (temp3)
            {
                return reverse_rec(temp2, temp3, temp3->next);
            }
            else
            {
                return reverse_rec(temp2, nullptr, nullptr);
            }
        }
        else
        {
            return temp1;
        }
    }
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode * temp1 = head,
                 * temp2 = SolutionSub::next(temp1),
                 * temp3 = SolutionSub::next(temp2);
        if (temp1)
        {
            temp1->next = nullptr;
            return SolutionSub::reverse_rec(temp1, temp2, temp3);
        }
        else
        {
            return nullptr;
        }
    }
};
