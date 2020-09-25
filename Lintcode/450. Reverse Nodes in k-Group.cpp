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
     * @param head: a ListNode
     * @param k: An integer
     * @return: a ListNode
     */
    ListNode * reverseKGroup(ListNode * head, int k) {
        ListNode* flag = new ListNode(0);
        flag->next = head;
        
        ListNode* cur = head, *prev = flag;
        while (cur) {
            ListNode* prob = cur, *prob_prev = nullptr;
            int i = 0;
            
            for (; i < k; i++) {
                if (prob == nullptr) break;
                
                prob_prev = prob;
                prob = prob->next;
            }
            
            if (i < k) {
                prev->next = cur;
                break;
            }
            
            rev(cur, prob);
            prev->next = prob_prev;
            prev = cur;
            cur = prob;
	}
        
	ListNode* ans = flag->next;
        delete flag;
        return ans;
    }
private:
    void rev(ListNode* start, ListNode* end) {
        ListNode* cur = start, *prev = nullptr;
        while (cur != end) {
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
    }
};
