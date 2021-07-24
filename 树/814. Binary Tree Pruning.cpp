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
        if (u == nullptr) return { nullptr, false };
        
        auto [l_root, l_have1] = dfs(u->left);
        auto [r_root, r_have1] = dfs(u->right);
        
        u->left = l_root;
        u->right = r_root;
        
        if (u->val == 1 || l_have1 || r_have1) {
            return { u, 1 };
        } else {
            return { nullptr, 0 };
        }
    }
};