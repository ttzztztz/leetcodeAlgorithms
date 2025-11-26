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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *left = headA, *right = headB;
        while (left != right) {
            if (left == nullptr) left = headB;
            else left = left->next;

            if (right == nullptr) right = headA;
            else right = right->next;
        }
        return left;
    }
};