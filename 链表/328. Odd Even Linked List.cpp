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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) return nullptr;

        ListNode* left_head = nullptr, *right_head = nullptr;
        ListNode* left_last = nullptr, *right_last = nullptr;

        ListNode* cur = head;
        int idx = 0;
        while (cur) {
            if (idx % 2 == 0) {
                if (left_last == nullptr) {
                    left_head = left_last = cur;
                } else {
                    left_last->next = cur;
                    left_last = cur;
                }
            } else {
                if (right_last == nullptr) {
                    right_head = right_last = cur;
                } else {
                    right_last->next = cur;
                    right_last = cur;
                }
            }
            
            idx++;
            cur = cur->next;
        }

        if (left_last != nullptr) {
            left_last->next = right_head;
        }
        if (right_last != nullptr) {
            right_last->next = nullptr;
        }
        return left_head;
    }
};