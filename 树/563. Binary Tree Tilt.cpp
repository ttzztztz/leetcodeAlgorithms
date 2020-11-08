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
    int findTilt(TreeNode* root) {
        dfs(root);
        return ans;
    }
private:
    int ans = 0;
    
    int dfs(TreeNode* u) {
        if (u == nullptr) return 0;
        
        const int l = dfs(u->left), r = dfs(u->right);
        ans += abs(l - r);
        return l + r + u->val;
    }
};
