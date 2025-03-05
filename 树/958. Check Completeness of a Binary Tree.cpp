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
    bool isCompleteTree(TreeNode* root) {
        return validate(root, 0, cnt(root));
    }
private:
    int cnt(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + cnt(root->left) + cnt(root->right);
    }

    bool validate(TreeNode* root, int idx, const int total) {
        if (root == nullptr) return true;
        if (idx >= total) return false;

        return validate(root->left, 2 * idx + 1, total) && validate(root->right, 2 * idx + 2, total);
    }
};