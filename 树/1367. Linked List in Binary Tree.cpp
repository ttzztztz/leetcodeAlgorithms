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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        this->list_head = head;
        return dfs(root, head);
    }
private:
    ListNode* list_head;
    bool dfs(TreeNode* root, ListNode* head) {
        if (head == nullptr) return true;
        if (root == nullptr) return false;
        
        if (root->val == head->val) {
            return dfs(root->left, head->next) || dfs(root->right, head->next);
        } else {
            return dfs(root->left, list_head) || dfs(root->right, list_head);
        }
    }
};