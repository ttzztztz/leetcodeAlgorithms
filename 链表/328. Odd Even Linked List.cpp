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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddBegin = new ListNode(0);
        ListNode* evenBegin = new ListNode(0);
        
        ListNode* flag = new ListNode(0);
        flag->next = head;
        
        int i = 1;
        ListNode* prev = flag, *cur = head;
        ListNode* curOdd = oddBegin, *curEven = evenBegin;
        while (cur) {
            ListNode* nxt = cur->next;
            if (i % 2 == 1) { // odd
                curOdd->next = cur;
                curOdd = curOdd->next;
                curOdd->next = nullptr;
            } else { // even
                curEven->next = cur;
                curEven = curEven->next;
                curEven->next = nullptr;
            }
            prev = cur;
            cur = nxt;
            i++;
        }
        
        curOdd->next = evenBegin->next;
        return oddBegin->next;
    }
};
