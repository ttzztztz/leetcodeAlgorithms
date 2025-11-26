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
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        return is_valid(
            root,
            numeric_limits<int>::min(),
            numeric_limits<int>::max()
        );
    }
private:
    bool is_valid(TreeNode* root, long long min_val, long long max_val) {
        if (root == nullptr) return true;
        long long val = root->val;

        if (!(min_val <= val && val <= max_val)) return false;
        return is_valid(root->left, min_val, val - 1) && is_valid(root->right, val + 1, max_val);
    }
};