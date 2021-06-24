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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* flag = new ListNode();
        flag->next = head;
        
        ListNode* prev = flag, *cur = head;
        for (int i = 0; i < left - 1; i++) {
            prev = cur;
            cur = cur->next;
        }
        ListNode* b = cur, *a = prev;
        for (int i = left - 1; i < right; i++) {
            prev = cur;
            cur = cur->next;
        }
        ListNode* c = cur;
        prev->next = nullptr;
        a->next = reverse(b);
        b->next = c;
        
        ListNode* ans = flag->next;
        delete flag;
        return ans;
    }
private:
    ListNode* reverse(ListNode* head) {
        ListNode* cur = head, *prev = nullptr;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};