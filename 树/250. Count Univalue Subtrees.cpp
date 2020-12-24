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
    int countUnivalSubtrees(TreeNode* root) {
        if (root == nullptr) return 0;
        dfs(root);
        return ans_;
    }
private:
    int ans_ = 0;
    
    int dfs(TreeNode* root) {
        if (root == nullptr) return 1;

        const int l = dfs(root->left);
        const int r = dfs(root->right);

        if (root->left && root->right) {
            if (root->val == root->left->val && root->val == root->right->val && l == 1 && r == 1) {
                ans_ += 1;
                return 1;
            }
        } else if (root->left) {
            if (root->val == root->left->val && l == 1) {
                ans_ += 1;
                return 1;
            }
        } else if (root->right) {
            if (root->val == root->right->val && r == 1) {
                ans_ += 1;
                return 1;
            }
        } else { // is_leaf
            ans_ += 1;
            return 1;
        }
        
        return -1;
    }
};
