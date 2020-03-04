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
    ListNode* swapPairs(ListNode* head) {
        ListNode* flag = new ListNode(0);
        flag->next = head;
        
        ListNode* prev = flag, *cur = head;
        while (cur) {
            if (cur->next == nullptr) break;
            ListNode* nxt = cur->next->next;
            ListNode* nxt_prev = cur->next;
            
            reverse(cur, nxt);
            prev->next = nxt_prev;
            cur->next = nxt;
            
            prev = cur;
            cur = nxt;
        }
        
        ListNode* answer = flag->next;
        delete flag;
        return answer;
    }
    ListNode* reverse(ListNode* start, ListNode* end) { // [start, end)
        ListNode* cur = start, *prev = nullptr;
        while (cur != end) {
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        return cur;
    }
};
