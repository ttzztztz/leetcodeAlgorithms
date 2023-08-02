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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) return nullptr; // len = 0
        if (head->next == nullptr) return head; // len = 1

        ListNode* middle = find_middle(head);
        ListNode* next_head = middle->next;
        middle->next = nullptr;

        ListNode* left = sortList(head);
        ListNode* right = sortList(next_head);
        return merge_list(left, right);
    }
private:
    ListNode* find_middle(ListNode* head) {
        ListNode *fast = head, *slow = head;
        while (fast) {
            if (fast->next != nullptr) fast = fast->next;
            else return slow;

            if (fast->next != nullptr) fast = fast->next;
            else return slow;

            slow = slow->next;
        }
        return slow;
    }

    ListNode* merge_list(ListNode* left, ListNode* right) {
        ListNode* flag = new ListNode();
        ListNode* cur = flag;
        while (left != nullptr && right != nullptr) {
            if (left->val <= right->val) {
                cur->next = left;
                cur = cur->next;
                left = left->next;
            } else {
                cur->next = right;
                cur = cur->next;
                right = right->next;
            }
        }

        if (left != nullptr) {
            cur->next = left;
        }

        if (right != nullptr) {
            cur->next = right;
        }
        ListNode* ans = flag->next;
        delete flag;
        return ans;
    }
};