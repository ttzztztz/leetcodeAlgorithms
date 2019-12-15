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
    int getDecimalValue(ListNode* head) {
        int answer = 0;

        vector<int> digit;
        while (head) {
            digit.push_back(head->val);
            head = head->next;
        }

        for (int i = 0; i < digit.size(); i++) {
            const int d = digit.size() - i - 1;

            answer += (1 << i) * digit[d];
        }

        return answer;
    }
};