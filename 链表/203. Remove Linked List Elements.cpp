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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* t = new ListNode();
        ListNode* prev = t, *cur = head;
        t->next = cur;
        
        while (cur != nullptr) {
            if (cur->val == val) {
                ListNode* will = cur;
                cur = cur->next;
                delete will;
                prev->next = cur;
            } else {
                prev = prev->next;
                cur = cur->next;
            }
        }
        
        return t->next;
    }
};
