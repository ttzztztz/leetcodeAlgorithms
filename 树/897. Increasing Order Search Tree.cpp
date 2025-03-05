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
    TreeNode* increasingBST(TreeNode* root) {
        if (root == nullptr) return nullptr;
        dfs(root);
        return ans;
    }
private:
    TreeNode* ans = nullptr;
    TreeNode* last = nullptr;

    void dfs(TreeNode* root) {
        if (root == nullptr) return;

        dfs(root->left);

        if (ans == nullptr) ans = root;
        if (last != nullptr) last->right = root;
        root->left = nullptr;
        last = root;

        dfs(root->right);
    }
};