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

struct Comp {
    bool operator()(ListNode* lhs, ListNode* rhs) const {
        return lhs->val > rhs->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Comp> heap;
        for (auto& list : lists) {
            if (list) heap.push(list);
        }
        
        ListNode* flag = new ListNode(0);
        ListNode* cur = flag;
        while (!heap.empty()) {
            ListNode* u = heap.top();
            heap.pop();
            
            cur->next = u;
            cur = cur->next;
            
            ListNode* next = u->next;
            if (next) {
                heap.push(next);
            }
        }
        
        ListNode* ans = flag->next;
        delete flag;
        return ans;
    }
};
