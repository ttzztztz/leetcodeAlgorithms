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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return nullptr;
        ListNode* cur = head;
        int len = 1;
        while (cur->next) cur = cur->next, len++;
        cur->next = head;
        
        ListNode* fast = head, *slow = cur;
        for (int i = 0; i < (len - k % len); i++) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = nullptr;
        return fast;
    }
};
