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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr) return nullptr;
        ListNode* flag1 = new ListNode(0);
        ListNode* flag2 = new ListNode(0);
        flag2->next = head;
        
        ListNode* prev = flag2, *cur = head, *ptr = flag1;
        while (cur) {
            if (cur->val < x) { // move
                ptr->next = cur;
                ptr = ptr->next;
                
                prev->next = cur->next;
                cur = cur->next;
            } else { // don't do anything
                prev = cur;
                cur = cur->next;
            }
        }
        
        ptr->next = flag2->next;
        return flag1->next;
    }
};
