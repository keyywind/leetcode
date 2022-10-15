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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode * newhead = head;
        for (; newhead && (newhead->val == val); newhead = newhead->next);
        if (newhead)
        {
            ListNode * tail = newhead,
                     * temp = newhead->next;
            for (; temp; temp = temp->next)
            {
                if (temp->val != val)
                {
                    tail->next = temp;
                    tail = tail->next;
                }
            }
            tail->next = nullptr;
        }
        return newhead;
    }
};
