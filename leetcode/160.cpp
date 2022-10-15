/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set <ListNode*> nodeSet;
        ListNode * temp;
        for (temp = headA; temp; temp = temp->next)
        {
            nodeSet.insert(temp);
        }
        for (temp = headB; temp; temp = temp->next)
        {
            if (nodeSet.find(temp) != nodeSet.end())
            {
                return temp;
            }
        }
        return nullptr;
    }
};
