/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class SolutionSub
{
public:
    static bool cycle(ListNode * head)
    {
        unordered_set <ListNode*> nodeSet;
        for (ListNode * temp = head; temp; temp = temp->next)
        {
            if (nodeSet.find(temp->next) == nodeSet.end())
            {
                nodeSet.insert(temp);
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        return SolutionSub::cycle(head);
    }
};
