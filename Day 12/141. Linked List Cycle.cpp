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
    bool hasCycle(ListNode *head) {
        ListNode *hare = head, *tort = head;
        while(hare != NULL)
        {
            hare = hare->next;
            if(hare == NULL)
            {
                break;
                
            }
            
            hare = hare->next;
            tort = tort->next;
            
            if(hare == tort)
            {
                return true;
            }
        }

        return false;
    }
};