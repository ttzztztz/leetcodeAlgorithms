/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    const int MOD = 1e9 + 7;
    long long answer = 0, total = 0;
    map<TreeNode*, pair<long long, long long>> sum;
    
    long long dfs1(TreeNode* u) {
        long long left_sum = 0, right_sum = 0;
        
        if (u->left) left_sum = dfs1(u->left);
        if (u->right) right_sum = dfs1(u->right);
        
        sum[u] = {left_sum, right_sum};
        return (left_sum + right_sum + u->val);
    }
    
    int maxProduct(TreeNode* root) {
        dfs1(root);
        total = root->val + sum[root].first + sum[root].second;

        for (auto& p : sum) {
            TreeNode* u = p.first;
            pair<long long, long long> _sum = p.second;
            
            if (u->left) {
                const long long s = (sum[u->left].first + sum[u->left].second + u->left->val);
                answer = max(answer, (total - s) * s);
            }
            
            if (u->right) {
                const long long s = sum[u->right].first + sum[u->right].second + u->right->val;
                answer = max(answer, (total - s) * s);
            }
        }
        
        return answer % MOD;
    }
};
