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
    int maxProduct(TreeNode* root) {
        ttl = dfs(root);
        dfs(root);
        const int mod = 1e9+7;
        return ans % mod;
    }
private:
    typedef long long ll;
    ll ans = 0, ttl = 0;
    
    ll dfs(TreeNode* u) {
        if (u == nullptr) return 0;
        
        ll val = u->val;
        const ll l = dfs(u->left);
        const ll r = dfs(u->right);
        
        ans = max(ans, max((ttl - r) * r, (ttl - l) * l));
        return val + l + r;
    }
};
