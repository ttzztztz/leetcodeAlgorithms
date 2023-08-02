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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;

        ListNode* flag = new ListNode();
        flag->next = head;

        ListNode* cur = head, *tail = nullptr, *prev = flag;
        while ((tail = advance(cur, k)) != nullptr) {
            ListNode* next_head = tail->next;
            tail->next = nullptr;
            prev->next = reverse(cur);
            prev = cur;
            cur = next_head;
        }

        if (cur != nullptr) {
            prev->next = cur;
        }
        ListNode* ans = flag->next;
        delete flag;
        return ans;
    }
private:
    ListNode* advance(ListNode* head, int k) {
        if (head == nullptr) return nullptr;

        for (int i = 0; i < k - 1; i++) {
            if (head->next == nullptr) return nullptr;
            head = head->next;
        }
        return head;
    }

    ListNode* reverse(ListNode* head) {
        // prev [cur] -> t
        // t := cur->next
        // cur->next = prev
        // prev = cur
        // cur = t
        ListNode* cur = head, *prev = nullptr;

        while (cur) {
            ListNode* t = cur->next;
            cur->next = prev;
            prev = cur;
            cur = t;
        }
        return prev;
    }
};