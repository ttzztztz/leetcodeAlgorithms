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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* flag = new ListNode();
        flag->next = head;
        
        ListNode *prev = flag, *cur = head;
        while (cur) {
            ListNode* prob = cur;
            
            bool ok = true;
            for (int i = 0; i < k; i++) {
                if (prob == nullptr) {
                    ok = false;
                    break;
                }
                prob = prob->next;
            }
            
            if (!ok) break;
            
            ListNode* new_head = reverse(cur, prob);
            prev->next = new_head;
            cur->next = prob;
            
            prev = cur;
            cur = prob;
        }
        
        ListNode* ans = flag->next;
        delete flag;
        return ans;
    }
private:
    ListNode* reverse(ListNode* head, ListNode* end) {
        ListNode* prev = nullptr, *cur = head;
        while (cur != end) {
            ListNode* t = cur->next;
            cur->next = prev;
            prev = cur;
            cur = t;
        }
        return prev;
    }
};