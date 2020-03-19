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
    TreeNode* mergeTrees(TreeNode* $1, TreeNode* $2) {
        if ($1 == nullptr && $2 == nullptr) return nullptr;
        TreeNode* root = new TreeNode();
        if ($1) root->val += $1->val;
        if ($2) root->val += $2->val;

        root->left = mergeTrees($1 == nullptr ? nullptr : $1->left, $2 == nullptr ? nullptr : $2->left);
        root->right = mergeTrees($1 == nullptr ? nullptr : $1->right, $2 == nullptr ? nullptr : $2->right);
        return root;
    }
};
