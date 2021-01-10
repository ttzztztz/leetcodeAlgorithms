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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* h1 = head;
        for (int i = 0; i < k - 1; i++) {
            h1 = h1->next;
        }
        
        ListNode *h2 = head, *h3 = h1;
        while (h3->next) {
            h2 = h2->next;
            h3 = h3->next;
        }
        
        swap(h2->val, h1->val);
        return head;
    }
};
