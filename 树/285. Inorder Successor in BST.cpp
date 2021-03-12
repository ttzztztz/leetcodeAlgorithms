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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* u = root, *parent = nullptr;
        while (u != p) {
            if (u->val < p->val) {
                u = u->right;
            } else { // u->val > p->val
                parent = u;
                u = u->left;
            }
        }
        
        TreeNode* right_left_most = nullptr;
        if (p->right) {
            u = p->right;
            while (u->left) u = u->left;
            right_left_most = u;
        }
        
        if (parent && right_left_most) {
            if (parent->val < right_left_most->val) return parent;
            else return right_left_most;
        } else if (parent) {
            return parent;
        } else if (right_left_most) {
            return right_left_most;
        } else {
            return nullptr;
        }
    }
};
