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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return nullptr;
        
        ListNode* prev = head, *cur = head->next;
        while (cur) {
            if (cur->val == prev->val) {
                ListNode* nxt = cur->next;
                delete cur;
                cur = nxt;
                prev->next = nxt;
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
        
        return head;
    }
};
