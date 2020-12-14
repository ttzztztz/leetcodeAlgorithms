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
    int longestUnivaluePath(TreeNode* root) {
        if (root == nullptr) return 0;
        dfs(root);
        return ans - 1;
    }
private:
    int ans = 0;
    int dfs(TreeNode* u) {
        if (u == nullptr) return 0;
        
        int l = 0, r = 0;
        if (u->left) {
            const int t = dfs(u->left);
            if (u->left->val == u->val) l = t;
        }
        
        if (u->right) {
            const int t = dfs(u->right);
            if (u->right->val == u->val) r = t;
        }
        
        ans = max(ans, l + r + 1);
        return max(l, r) + 1;
    }
};
