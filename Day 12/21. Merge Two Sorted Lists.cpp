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
        ListNode* head = new ListNode(-1);
        ListNode* ans = head;

        while(list1 != NULL && list2 != NULL)
        {
            if(list1->val < list2->val)
            {
                ListNode* curr = new ListNode(list1->val);
                ans->next = curr;

                ans = curr;
                list1 = list1->next;
            }
            else
            {
                ListNode* curr = new ListNode(list2->val);
                ans->next = curr;

                ans = curr;
                list2 = list2->next;
            }
        }

        while(list1 != NULL)
        {
            ListNode* curr = new ListNode(list1->val);
            ans->next = curr;

            ans = curr;
            list1 = list1->next;
        }

        while(list2 != NULL)
        {
            ListNode* curr = new ListNode(list2->val);
            ans->next = curr;

            ans = curr;
            list2 = list2->next;
        }

        return head->next;
    }
};