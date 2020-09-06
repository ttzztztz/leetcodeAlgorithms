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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> arr;
        while (head) {
            arr.push_back(head->val);
            head = head->next;
        }
        
        const int N = arr.size();
        typedef pair<int, int> PII;
        
        vector<int> answer(N, 0);
        vector<int> stk;
        for (int i = N - 1; i >= 0; i--) {
            while (!stk.empty() && stk.back() <= arr[i]) stk.pop_back();
            
            if (!stk.empty()) answer[i] = stk.back();
            else answer[i] = 0;
            
            stk.push_back(arr[i]);
        }
        return answer;
    }
};
