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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> n1, n2;
        ListNode* cur = l1;
        while (cur) {
            n1.push_back(cur->val);
            cur = cur->next;
        }
        
        cur = l2;
        while (cur) {
            n2.push_back(cur->val);
            cur = cur->next;
        }
        
        reverse(n1.begin(), n1.end());
        reverse(n2.begin(), n2.end());
        vector<int> answer;
        int more = 0;
        for (int i = 0; i < max(n1.size(), n2.size()); i++) {
            int d = (i < n1.size() ? n1[i] : 0) + (i < n2.size() ? n2[i] : 0) + more;
            if (d >= 10) {
                d -= 10;
                more = 1;
            } else {
                more = 0;
            }
            
            answer.push_back(d);
        }
        
        if (more) answer.push_back(1);
        reverse(answer.begin(), answer.end());
        
        ListNode* prev = nullptr;
        cur = l1;
        for (int i = 0; i < answer.size(); i++) {
            if (cur == nullptr) {
                prev->next = new ListNode(answer[i]);
                prev = prev->next;
                cur = nullptr;
            } else {
                cur->val = answer[i];
                prev = cur;
                cur = cur->next;
            }
        }
        return l1;
    }
};