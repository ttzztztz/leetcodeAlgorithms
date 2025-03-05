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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) return nullptr;

        ListNode* slow = head, *fast = head;
        do {
            fast = fast->next;
            if (fast == nullptr) return nullptr;
    
            fast = fast->next;
            if (fast == nullptr) return nullptr;
    
            slow = slow->next;
        } while (slow != fast);

        slow = head;
        while (fast != slow) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};