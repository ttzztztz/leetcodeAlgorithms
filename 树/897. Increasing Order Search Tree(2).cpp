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
    TreeNode* increasingBST(TreeNode* root) {
        if (root == nullptr) return nullptr;
        dfs(root);
        
        TreeNode* new_root = new TreeNode(all_.front());
        TreeNode* cur = new_root;
        for (int i = 1; i < all_.size(); i++) {
            cur->right = new TreeNode(all_[i]);
            cur = cur->right;
        }
        return new_root;
    }
private:
    vector<int> all_;
    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        
        dfs(root->left);
        all_.push_back(root->val);
        dfs(root->right);
    }
};
