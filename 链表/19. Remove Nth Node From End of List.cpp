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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) return nullptr;

        ListNode *prev_slow = nullptr, *slow = head, *fast = head;
        for (int i = 0; i < n - 1; i++) fast = fast->next;
        while (fast->next != nullptr) {
            prev_slow = slow;
            slow = slow->next;
            fast = fast->next;
        }

        if (prev_slow == nullptr) {
            ListNode* ans = head->next;
            delete head;
            return ans;
        }
        prev_slow->next = slow->next;
        delete slow;
        return head;
    }
};