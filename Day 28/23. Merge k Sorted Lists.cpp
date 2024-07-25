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
    // Greater than operator comparator
    class cmp
    {
        public:
            const bool operator()(const ListNode* a, const ListNode* b)
            {
                return a->val > b->val;
            }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        //  Greater than operator is used for minheaps
        ListNode* head = new ListNode(-1), *t = head;

        for(auto &i: lists)
        {
            if(i != NULL)
            {
                pq.push(i);
            }
        }

        while(!pq.empty())
        {
            ListNode* cur = pq.top();
            pq.pop();

            t->next = cur;
            t = t->next;

            if(cur->next != NULL)
            {
                pq.push(cur->next);
            }
        }

        head = head->next;
        return head;
    }
};