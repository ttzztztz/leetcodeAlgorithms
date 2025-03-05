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
        return validate(root);
    }
private:
    bool is_first = true;
    int last_val = 0;

    bool validate(TreeNode* root) {
        if (root == nullptr) return true;

        bool result = true;

        result = result && validate(root->left);
        if (!is_first && last_val >= root->val) return false;
        is_first = false;
        last_val = root->val;
        result = result && validate(root->right);

        return result;
    }
};