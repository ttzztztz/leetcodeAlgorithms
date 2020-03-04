/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return new TreeNode(head->val);
        
        ListNode* mid = middle(head);
        
        TreeNode* root = new TreeNode(mid->val);
        if (head != mid) root->left = sortedListToBST(head);
        if (mid) root->right = sortedListToBST(mid->next);
        
        return root;
    }
private:
    ListNode* middle(ListNode* head) {
        ListNode* fast = head, *slow = head, *prev = nullptr;
        while (fast) {
            if (fast->next) fast = fast->next;
            else {
                if (prev) prev->next = nullptr;
                return slow;
            }
            
            if (fast->next) fast = fast->next;
            else {
                if (prev) prev->next = nullptr;
                return slow;
            }
            
            prev = slow;
            slow = slow->next;
        }
        
        if (prev) prev->next = nullptr;
        return slow;
    }
};
