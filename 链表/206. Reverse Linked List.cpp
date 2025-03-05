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
    ListNode* reverseList(ListNode* head) {
        // Write your code here
  
        if (head == nullptr) return nullptr;
        
        // o -> x -> y
        // x -> o -> y
        
        // (cur = x)
        // cur = x, prev = o
        // p := cur.next
        // cur.next = prev
        // prev = cur
        // cur = p
        
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