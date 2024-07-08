class LRUCache {
public:
    class ListNode{
        public:
            int key;
            int val;
            ListNode* prev;
            ListNode* next;

            ListNode(int key, int val)
            {
                this->key = key;
                this->val = val;
            }
    };

    ListNode* head = new ListNode(-1, -1);
    ListNode* tail = new ListNode(-1, -1);
    int mxsize;
    unordered_map<int, ListNode*> mp;

    LRUCache(int capacity) {
        mxsize = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addListNode(ListNode* node)
    {
        ListNode* nxt = head->next;
        node->next = nxt;
        node->prev = head;

        head->next = node;
        nxt->prev = node;
    }

    void deleteListNode(ListNode* node)
    {
        ListNode* pre = node->prev;
        ListNode* nxt = node->next;
        pre->next = nxt;
        nxt->prev = pre;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end())
        {
            ListNode* ans = mp[key];
            int val = ans->val;

            mp.erase(key);
            deleteListNode(ans);
            addListNode(ans);

            mp[key] = head->next;
            return val;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end())
        {
            ListNode* cur = mp[key];
            mp.erase(key);
            deleteListNode(cur);
        }

        if(mp.size() == mxsize)
        {
            mp.erase(tail->prev->key);
            deleteListNode(tail->prev);
        }

        addListNode(new ListNode(key, value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */