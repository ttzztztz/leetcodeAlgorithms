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
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr) return nullptr;

        ListNode *slow = head, *fast = head;
        while (fast != nullptr) {
            if (fast) fast = fast->next;
            else return slow;

            if (fast) fast = fast->next;
            else return slow;

            slow = slow->next;
        }
        return slow;
    }
};