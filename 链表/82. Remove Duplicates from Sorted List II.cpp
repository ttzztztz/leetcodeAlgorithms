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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode* ans = nullptr, *prev = nullptr, *cur = head;
        while (cur) {
            bool duplicated = false;
            while (cur->next != nullptr && cur->val == cur->next->val) {
                duplicated = true;
                cur = cur->next;
            }

            if (!duplicated) {
                if (ans == nullptr) ans = cur;
                if (prev != nullptr) prev->next = cur;
                prev = cur;
            }
            cur = cur->next;
        }

        if (prev != nullptr) prev->next = nullptr;
        return ans;
    }
};