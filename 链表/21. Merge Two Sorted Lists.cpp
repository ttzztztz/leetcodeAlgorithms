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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr, * curr = nullptr;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                if (head == nullptr) {
                    curr = head = l1;
                } else {
                    curr->next = l1;
                    curr = l1;
                }
                l1 = l1->next;
            } else {
                if (head == nullptr) {
                    curr = head = l2;
                } else {
                    curr->next = l2;
                    curr = l2;
                }
                l2 = l2->next;
            }
        }

        if (l1 != nullptr) {
            if (head == nullptr) {
                head = curr = l1;
            } else {
                curr->next = l1;
            }
        }
        if (l2 != nullptr) {
            if (head == nullptr) {
                head = curr = l2;
            } else {
                curr->next = l2;
            }
        }

        return head;
    }
};