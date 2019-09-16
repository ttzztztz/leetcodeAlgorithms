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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *ptr1 = head, *ptr2 = head, *ptr3 = head;
        for (int i = 1; i < n; i++) {
            ptr1 = ptr1->next;
        }

        bool isFirst = true;
        while (ptr1->next != nullptr) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            if (isFirst) {
                isFirst = false;
            } else {
                ptr3 = ptr3->next;
            }
        }

        ptr3->next = ptr2->next;
        return head == ptr2 ? ptr2->next : head;
    }
};