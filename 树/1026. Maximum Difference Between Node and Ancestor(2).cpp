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
    int maxAncestorDiff(TreeNode* root) {
        dfs(root, root->val, root->val);
        return ans;
    }
private:
    int ans = 0;
    
    void dfs(TreeNode* u, int mi, int ma) {
        if (u == nullptr) return;
        ans = max(ans, max(ma, u->val) - min(mi, u->val));
        
        dfs(u->left, min(mi, u->val), max(ma, u->val));
        dfs(u->right, min(mi, u->val), max(ma, u->val));
    }
};
