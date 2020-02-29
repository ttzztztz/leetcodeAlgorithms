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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* flag = new ListNode(0);
        flag->next = head;
        
        ListNode* cur = head, *prev = flag;
        while (cur) {
            ListNode* probe = cur, *prob_prev = nullptr;
            
            int i = 0;
            for (; i < k; i++) {
                if (probe == nullptr) break;
                prob_prev = probe;
                probe = probe->next;
            }
            
            if (i < k) {
                prev->next = cur;
                break;
            }
            
            reverse(cur, probe);
            prev->next = prob_prev;
            prev = cur;
            cur = probe;
        }
        
        return flag->next;
    }
private:
    void reverse(ListNode* start, ListNode* end) {
        ListNode* cur = start, *prev = nullptr;
        while (cur != end) {
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
    }
};
