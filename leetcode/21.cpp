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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * temp1 = list1,
                 * temp2 = list2,
                 * list3 = nullptr,
                 * temp3 = nullptr;
        while (temp1 && temp2)
        {
            if (temp1->val < temp2->val)
            {
                if (list3)
                {
                    temp3->next = temp1;
                    temp3       = temp3->next;
                    temp1       = temp1->next;
                }
                else
                {
                    list3 = temp1;
                    temp3 = list3;
                    temp1 = temp1->next;
                }
            }
            else
            {
                if (list3)
                {
                    temp3->next = temp2;
                    temp3       = temp3->next;
                    temp2       = temp2->next;
                }
                else
                {
                    list3 = temp2;
                    temp3 = list3;
                    temp2 = temp2->next;
                }
            }
        }
        for (; temp1; temp1 = temp1->next)
        {
            if (list3)
            {
                temp3->next = temp1;
                temp3       = temp3->next;
            }
            else
            {
                list3 = temp1;
                temp3 = list3;
            }
        }
        for (; temp2; temp2 = temp2->next)
        {
            if (list3)
            {
                temp3->next = temp2;
                temp3       = temp3->next;
            }
            else
            {
                list3 = temp2;
                temp3 = list3;
            }
        }
        if (temp3)
            temp3->next = nullptr;
        return list3;
    }
};
