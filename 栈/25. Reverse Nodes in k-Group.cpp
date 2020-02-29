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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head, *prev = nullptr;
        vector<int> stk;
        while (cur != nullptr) {
            ListNode* tmp = cur;
            for (int i = 0; i < k; i++) {
                if (tmp == nullptr) break;
                stk.push_back(tmp->val);
                tmp = tmp->next;
            }
            
            if (stk.size() < k) break;
            for (int i = 0; i < k; i++) {
                cur->val = stk.back();
                stk.pop_back();
                prev = cur;
                cur = cur->next;
            }
        }
        
        return head;
    }
};
