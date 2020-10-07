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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* u = root;
        if (u == nullptr) return new TreeNode(val);
        if (val < u->val) {
            u->left = insertIntoBST(u->left, val);
        } else if (val > u->val) {
            u->right = insertIntoBST(u->right, val);
        }
        
        return root;
    }
};
