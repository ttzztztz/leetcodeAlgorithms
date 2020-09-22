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
     * @param head: The first node of linked list.
     * @return: The node where the cycle begins. if there is no cycle, return null
     */
    ListNode * detectCycle(ListNode * head) {
        if (head == nullptr) return nullptr;
        
        ListNode* fast = head, *slow = head;
        do {
            if (fast->next) fast = fast->next;
            else return nullptr;
            
            if (fast->next) fast = fast->next;
            else return nullptr;
            
            slow = slow->next;
        } while (fast != slow);
        
        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};
