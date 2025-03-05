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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return {};

        ans.push_back(root->val);
        if (root->left) dfs(root->left, true, false);
        if (root->right) dfs(root->right, false, true);
        return ans;
    }
private:
    vector<int> ans;

    void dfs(TreeNode* u, bool is_left, bool is_right) {
        if (u == nullptr) return;

        const bool is_leaf = u->left == nullptr && u->right == nullptr;
        if (is_left && !is_right) ans.push_back(u->val);
        if (is_leaf && !is_left && !is_right) ans.push_back(u->val);
        dfs(u->left, is_left, is_right && u->right == nullptr);
        dfs(u->right, is_left && u->left == nullptr, is_right);
        if (is_right && !is_left) ans.push_back(u->val);
    }
};