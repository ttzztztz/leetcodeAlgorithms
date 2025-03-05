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
    void reorderList(ListNode* head) {
        if (head == nullptr) return;

        ListNode* middle = find_middle(head);
        ListNode* head1 = head, *head2 = middle->next;
        middle->next = nullptr;
        head2 = reverse(head2);

        ListNode* ptr1 = head1, *ptr2 = head2;
        while (ptr1 != nullptr && ptr2 != nullptr) {
            ListNode* ptr1_next = ptr1->next;
            ListNode* ptr2_next = ptr2->next;

            ptr1->next = ptr2;
            ptr2->next = ptr1_next;

            ptr1 = ptr1_next;
            ptr2 = ptr2_next;
        }
    }
private:
    ListNode* find_middle(ListNode* head) {
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

    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr, *cur = head;
        while (cur != nullptr) {
            // [prev] -> [cur]
            ListNode* cur_next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = cur_next;
        }
        return prev;
    }
};