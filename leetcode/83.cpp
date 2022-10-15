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
    ListNode* deleteDuplicates(ListNode* head) {
        #include <cstring>
        #define TABLE_SIZE 201
        #define TABLE_POSI TABLE_SIZE / 2
        bool array[TABLE_SIZE], * position = &(array[TABLE_POSI]);
        memset(array, 1, sizeof(bool) * TABLE_SIZE);
        if (head)
        {
            position[head->val] = false;
            ListNode * temp = head->next,
                     * tail = head;
            for (; temp; temp = temp->next)
            {
                if (position[temp->val])
                {
                    tail->next = temp;
                    tail = tail->next;
                    position[temp->val] = false;
                }
            }
            tail->next = nullptr;
        }
        return head;
    }
};
