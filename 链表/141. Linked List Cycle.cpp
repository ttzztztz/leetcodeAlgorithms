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
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;

        ListNode *slow = head, *fast = head;
        do {
            if (fast->next == nullptr) return false;
            fast = fast->next;

            if (fast->next == nullptr) return false;
            fast = fast->next;

            slow = slow->next;
        } while (slow != fast);

        return true;
    }
};