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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* flag = new ListNode(10005);
        flag->next = head;
        unordered_set<int> willDelete;

        ListNode* cur = head, *prev = flag;
        while (cur != nullptr) {
            if (cur->val == prev->val) { // delete
                willDelete.insert(cur->val);
            }

            prev = cur;
            cur = cur->next;
        }

        cur = head;
        prev = flag;

        while (cur != nullptr) {
            if (willDelete.count(cur->val)) {
                ListNode* tmp = cur->next;
                ListNode* willDelete = cur;
                delete willDelete;
                prev->next = tmp;
                cur = tmp;
            } else {
                prev = cur;
                cur = cur->next;
            }
        }

        ListNode* answer = flag->next;
        delete flag;
        return answer;
    }
};
