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
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head, *slow = head;
        while (fast) {
            if (fast->next) fast = fast->next;
            else return slow;
            
            slow = slow->next;
            
            if (fast->next) fast = fast->next;
            else return slow;
        }
        
        return slow;
    }
};
