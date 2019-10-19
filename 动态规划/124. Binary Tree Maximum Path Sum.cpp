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
    int total = -99999999;
    int solve(TreeNode* root) {
        if (nullptr == root) {
            return 0;
        }
        int answer = 0;

        int left = std::max(0, solve(root->left));
        int right = std::max(0, solve(root->right));

        answer = left + right + root->val;
        total = std::max(total, answer);

        return root->val + std::max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        solve(root);

        return total;
    }
};