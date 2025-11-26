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
        if (root == nullptr) return 0;

        dfs(root);
        return ans;
    }
private:
    int ans = numeric_limits<int>::min();

    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;

        const int l = dfs(root->left);
        const int r = dfs(root->right);
        const int cur = root->val;

        const int max_path = max(cur, max(
            l + cur,
            max(
                r + cur,
                l + r + cur
            )
        ));

        ans = max(ans, max_path);
        return max(
            cur,
            max(
                l + cur,
                r + cur
            )
        );
    }
};