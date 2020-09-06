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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return head;
        ListNode* mid = middle(head);
        
        ListNode* second = mid->next;
        mid->next = nullptr;
        
        ListNode* $1 = sortList(head);
        ListNode* $2 = sortList(second);
        
        return merge($1, $2);
    }
private:
    ListNode* middle(ListNode* start) {
        ListNode *fast = start, *slow = start;
        while (fast) {
            if (fast->next) fast = fast->next;
            else return slow;
            
            if (fast->next) fast = fast->next;
            else return slow;
            
            slow = slow->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* $1, ListNode* $2) {
        ListNode* flag = new ListNode(0);
        
        ListNode* cur = flag;
        while ($1 && $2) {
            if ($1->val < $2->val) {
                cur->next = $1;
                cur = cur->next;
                $1 = $1->next;
            } else {
                cur->next = $2;
                cur = cur->next;
                $2 = $2->next;
            }
        }
        if ($1) {
            cur->next = $1;
        }
        if ($2) {
            cur->next = $2;
        }
        
        ListNode* answer = flag->next;
        delete flag;
        return answer;
    }
};
