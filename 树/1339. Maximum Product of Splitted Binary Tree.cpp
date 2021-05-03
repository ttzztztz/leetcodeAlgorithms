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
        root_sum = dfs2(root);
        
        dfs(root);
        const int mod = 1e9+7;
        return ans % mod;
    }
private:
    typedef long long ll;
    ll ans = 0;
    ll root_sum = 0;
    
    ll dfs2(TreeNode* u) {
        if (u == nullptr) return 0;
        
        const ll l = dfs2(u->left);
        const ll r = dfs2(u->right);
        
        ll total_sum = l + r + u->val;
        return total_sum;
    }

    ll dfs(TreeNode* u) {
        if (u == nullptr) return 0;
        
        const ll l = dfs(u->left);
        const ll r = dfs(u->right);
        
        ll total_sum = l + r + u->val;
        ans = max(ans, (root_sum - l) * l);
        ans = max(ans, (root_sum - r) * r);
        return total_sum;
    }
};