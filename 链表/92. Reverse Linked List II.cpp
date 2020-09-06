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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == nullptr) return nullptr;
        
        ListNode* cur = head, *prev = nullptr;
        while (m > 1) {
            prev = cur;
            cur = cur->next;
            m--, n--;
        }
        
        ListNode* tail = cur, *first_con = prev;
        while (n > 0) {
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
            n--;
        }
        
        if (first_con == nullptr) head = prev;
        else first_con->next = prev;
        
        tail->next = cur;
        return head;
    }
};
