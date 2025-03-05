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
    int maxPathSum(TreeNode* root) {
        if (root == nullptr) return ans;

        dfs(root);
        return ans;
    }
private:
    int ans = numeric_limits<int>::min();

    int dfs(TreeNode* cur) {
        if (cur == nullptr) return 0;

        const int l_val = dfs(cur->left);
        const int r_val = dfs(cur->right);

        ans = max(ans, max(cur->val + l_val + r_val, max(cur->val, max(cur->val + l_val, cur->val + r_val))));
        return max(cur->val, cur->val + max(l_val, r_val));
    }
};