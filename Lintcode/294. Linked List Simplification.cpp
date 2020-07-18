/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param head: the linked list to be simplify.
     * @return: return the linked list after simplifiction.
     */
    ListNode * simplify(ListNode * head) {
        ListNode* cur = head->next;
        ListNode* tail = nullptr;
        int cnt = 0;
        
        while (cur) {
            tail = cur;
            cur = cur->next;
            cnt++;
        }
        cnt--;
        
        vector<int> all;
        while (cnt) {
            all.push_back(cnt % 10);
            cnt /= 10;
        }
        reverse(all.begin(), all.end());
        ListNode* nx = new ListNode(all[0] + '0');
        head->next = nx;
        
        cur = nx;
        for (int i = 1; i < all.size(); i++) {
            ListNode* c = new ListNode(all[i] + '0');
            cur->next = c;
            cur = c;
        }
        cur->next = tail;
        return head;
    }
};
