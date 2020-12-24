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
    int longestConsecutive(TreeNode* root) {
        if (root == nullptr) return 0;
        
        dfs(root);
        return ans_;
    }
private:
    int ans_ = 0;
    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int ans = 1;
        if (root->left) {
            const int t = dfs(root->left);
            if (root->val + 1 == root->left->val) ans = max(ans, 1 + t);
        }
        if (root->right) {
            const int t = dfs(root->right);
            if (root->val + 1 == root->right->val) ans = max(ans, 1 + t);
        }
        ans_ = max(ans_, ans);
        return ans;
    }
};
