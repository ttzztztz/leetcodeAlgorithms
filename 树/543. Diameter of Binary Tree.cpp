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
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans;
    }
private:
    int ans = 0;
    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;

        const int l = dfs(root->left);
        const int r = dfs(root->right);
        ans = max(ans, l + r);
        return 1 + max(l, r);
    }
};