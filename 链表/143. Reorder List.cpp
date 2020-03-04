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
    void reorderList(ListNode* head) {
        if (head == nullptr) return;
        
        ListNode* mid = middle(head);
        ListNode* second = mid->next;
        mid->next = nullptr;
        
        second = reverse(second);
        merge(head, second);
    }
private:
    ListNode* reverse(ListNode* head) {
        ListNode* cur = head, *prev = nullptr;
        while (cur) {
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
    ListNode* middle(ListNode* head) {
        ListNode* fast = head, *slow = head;
        while (fast) {
            if (fast->next) fast = fast->next;
            else return slow;
            
            if (fast->next) fast = fast->next;
            else {
                return slow;
            }
            
            slow = slow->next;
        }
        return slow;
    }
    void merge(ListNode* $1, ListNode* $2) {
        ListNode* flag = new ListNode(0);
        flag->next = $1;
        
        ListNode* prev = flag;
        int i = 0;
        while ($1 && $2) {
            if (i % 2 == 0) { // use 1
                prev->next = $1;
                prev = $1;
                $1 = $1->next;
            } else { // use 2
                prev->next = $2;
                prev = $2;
                $2 = $2->next;
            }
            
            i++;
        }
        if ($1) {
            prev->next = $1;
        }
        if ($2) {
            prev->next = $2;
        }
        
        delete flag;
    }
};
