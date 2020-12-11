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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> nodes;
        for (int i : nums) nodes.push_back(new TreeNode(i));
        const int n = nums.size();
        
        vector<TreeNode*> f(n, nullptr), g(n, nullptr);
        
        vector<int> stk;
        for (int i = 0; i < n; i++) {
            const int val = nums[i];
            while (!stk.empty() && nodes[stk.back()]->val < val) {
                stk.pop_back();
            }
            
            if (stk.empty()) f[i] = nullptr;
            else f[i] = nodes[stk.back()];
            
            stk.push_back(i);
        }
        stk.clear();
        for (int i = n - 1; i >= 0; i--) {
            const int val = nums[i];
            while (!stk.empty() && nodes[stk.back()]->val < val) {
                stk.pop_back();
            }
            
            if (stk.empty()) g[i] = nullptr;
            else g[i] = nodes[stk.back()];
            
            stk.push_back(i);
        }
        
        TreeNode* ans = nullptr;
        for (int i = 0; i < n; i++) {
            if (f[i] == nullptr && g[i] == nullptr) {
                ans = nodes[i];
            } else if (f[i] && g[i]) {
                const int l = f[i]->val, r = g[i]->val;
                if (l < r) {
                    f[i]->right = nodes[i];
                } else { // l > r
                    g[i]->left = nodes[i];
                }
            } else if (f[i]) {
                f[i]->right = nodes[i];
            } else { // g[i]
                g[i]->left = nodes[i];
            }
        }
        
        return ans;
    }
};
