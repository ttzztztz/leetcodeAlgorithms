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

        ListNode* slow = head, * fast = head;
        do {
            if (fast->next == nullptr) return nullptr;
            else fast = fast->next;

            if (fast->next == nullptr) return nullptr;
            else fast = fast->next;

            slow = slow->next;
        } while (slow != fast);

        slow = head;
        while (slow != fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};