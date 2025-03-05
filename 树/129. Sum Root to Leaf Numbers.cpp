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
    int sumNumbers(TreeNode* root) {
        if (root == nullptr) return 0;
        dfs(root, root->val);
        return ans;
    }
private:
    int ans = 0;

    void dfs(TreeNode* root, int cur) {
        const bool is_leaf = root->left == nullptr && root->right == nullptr;
        if (is_leaf) {
            ans += cur;
            return;
        }

        if (root->left) dfs(root->left, cur * 10 + root->left->val);
        if (root->right) dfs(root->right, cur * 10 + root->right->val);
    }
};