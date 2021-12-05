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
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr) return nullptr;
        
        ListNode* flag = new ListNode();
        flag->next = head;
        
        ListNode *fast = head, *slow = head, *slow_prev = flag;
        while (fast->next) {
            if (fast->next) fast = fast->next;
            else {
                slow_prev = slow;
                slow = slow->next;
                break;
            }
            
            if (fast->next) fast = fast->next;
            else {
                slow_prev = slow;
                slow = slow->next;
                break;
            }
            
            slow_prev = slow;
            slow = slow->next;
        }
        
        slow_prev->next = slow->next;
        delete slow;
        return flag->next;
    }
};
