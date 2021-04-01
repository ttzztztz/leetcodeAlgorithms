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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) return true;

        ListNode* middle = get_middle(head);
        ListNode* cur = middle->next;
        middle->next = nullptr;
        cur = reverse(cur);
        
        while (head && cur) {
            if (head->val != cur->val) {
                return false;
            }

            head = head->next;
            cur = cur->next;
        }
        return true;
    }
private:
    ListNode* get_middle(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while (fast) {
            if (fast->next) fast = fast->next;
            else return slow;
            
            if (fast->next) fast = fast->next;
            else return slow;
            
            slow = slow->next;
        }
        return slow;
    }
    
    ListNode* reverse(ListNode* head) {
        ListNode* cur = head, *prev = nullptr;
        while (cur) {
            ListNode* t = cur->next;
            cur->next = prev;
            prev = cur;
            cur = t;
        }
        return prev;
    }
};