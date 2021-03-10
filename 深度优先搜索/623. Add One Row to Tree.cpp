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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode* new_root = new TreeNode(v);
            new_root->left = root;
            return new_root;
        }

        if (d - 1 == 1) {
            TreeNode* prev = root->left;
            root->left = new TreeNode(v);
            root->left->left = prev;
            
            prev = root->right;
            root->right = new TreeNode(v);
            root->right->right = prev;
            return root;
        }

        if (root->left) root->left = addOneRow(root->left, v, d - 1);
        if (root->right) root->right = addOneRow(root->right, v, d - 1);
        return root;
    }
};