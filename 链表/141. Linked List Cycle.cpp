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
        if (head == nullptr) {
            return false;
        }

        ListNode *fast = head, *slow = head;
        do {
            for (int i = 0; i < 2; i++) {
                if (fast->next == nullptr) {
                    return false;
                }
                fast = fast->next;
            }

            slow = slow->next;
        } while (fast != slow);
        return true;
    }
};