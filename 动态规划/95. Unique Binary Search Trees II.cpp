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
    vector<TreeNode*> generateTrees(int n) {
        this->n = n;
        return dfs(1, n);
    }
private:
    unordered_map<int, vector<TreeNode*>> memo;
    int n;
    int hash(int l, int r) {
        return l * (n + 1) + r;
    }
    
    vector<TreeNode*> dfs(int l, int r) {
        if (l > r) return { nullptr };
        else if (l == r) return { new TreeNode(l) };

        const int h = hash(l, r);
        if (memo.count(h)) return memo[h];
        
        vector<TreeNode*> ans;
        for (int u = l; u <= r; u++) {
            auto left = dfs(l, u - 1);
            auto right = dfs(u + 1, r);
            
            for (auto& l_child : left) for (auto& r_child : right) {
                TreeNode* cur = new TreeNode(u);
                cur->left = l_child;
                cur->right = r_child;
                ans.push_back(cur);
            }
        }
        return memo[h] = ans;
    }
};