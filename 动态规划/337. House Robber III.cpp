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
    unordered_map<TreeNode*, int> dp;
    int rob(TreeNode* root) {
        if (dp.count(root)) {
            return dp[root];
        }

        if (nullptr == root) {
            return 0;
        } else if (root->left == root->right && root->left == nullptr) {
            return root->val;
        } else {
            int select = root->val, noSelect = 0;
            if (root->left != nullptr) {
                noSelect += rob(root->left);

                select += rob(root->left->left) + rob(root->left->right);
            }

            if (root->right != nullptr) {
                noSelect += rob(root->right);

                select += rob(root->right->left) + rob(root->right->right);
            }

            return dp[root] = std::max(select, noSelect);
        }
    }
};