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
    TreeNode* pruneTree(TreeNode* root) {
        return dfs(root).first;
    }
private:
    pair<TreeNode*, bool> dfs(TreeNode* u) {
        if (u == nullptr) return {nullptr, true};
        
        auto [t1, b1] = dfs(u->left);
        auto [t2, b2] = dfs(u->right);
        
        if (u->val == 0 && b1 && b2) {
            return {nullptr, true};
        }
        
        u->left = t1;
        u->right = t2;
        
        return {u, false};
    }
};
