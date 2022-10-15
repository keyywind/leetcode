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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * temp1 = l1,
                 * temp2 = l2,
                 * tempf = new ListNode(),
                 * tempp = nullptr,
                 * tempt = tempf;
        int carry = 0, addition;
        for (; temp1 && temp2; temp1 = temp1->next, temp2 = temp2->next)
        {
            addition    = temp1->val + temp2->val + carry;
            carry       = addition / 10;
            tempt->val  = addition % 10;
            tempt->next = new ListNode(carry);
            tempp       = tempt;
            tempt       = tempt->next;
        }
        for (; temp1; temp1 = temp1->next)
        {
            addition    = temp1->val + carry;
            carry       = addition / 10;
            tempt->val  = addition % 10;
            tempt->next = new ListNode(carry);
            tempp       = tempt;
            tempt       = tempt->next;
        }
        for (; temp2; temp2 = temp2->next)
        {
            addition    = temp2->val + carry;
            carry       = addition / 10;
            tempt->val  = addition % 10;
            tempt->next = new ListNode(carry);
            tempp       = tempt;
            tempt       = tempt->next;
        }
        if (tempt->val == 0)
        {
            tempp->next = nullptr;
            delete tempt;
        }
        return tempf;
    }
};
