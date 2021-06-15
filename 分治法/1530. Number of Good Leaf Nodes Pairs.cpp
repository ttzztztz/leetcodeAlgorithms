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
    int countPairs(TreeNode* root, int distance) {
        this->d = distance;
        dfs(root);
        return ans;
    }
private:
    int ans = 0, d = 0;
    vector<int> dfs(TreeNode* u) {
        vector<int> t(11, 0);
        if (u == nullptr) {
            return t;
        }
        if (u->left == nullptr && u->right == nullptr) {
            t[1] = 1;
            return t;
        }
        
        vector<int> f = dfs(u->left), g = dfs(u->right);
        for (int l = 1; l <= 10; l++) for (int r = 1; r <= 10; r++) {
            if (l + r <= d) ans += f[l] * g[r];
        }

        for (int i = 1; i <= 10; i++) t[i] = f[i - 1] + g[i - 1];
        return t;
    }
};