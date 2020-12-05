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
    string smallestFromLeaf(TreeNode* root) {
        Dfs(root);

        return str_;
    }
private:
    string str_;
    string cur_;
    void Update(string str) {
        reverse(str.begin(), str.end());
        if (str_.empty()) {
            str_ = str;
            return;
        }
        str_ = min(str_, str);
    }
    
    void Dfs(TreeNode* root) {
        if (root == nullptr) return;
        cur_.push_back('a' + root->val);
        bool is_leaf = root->left == nullptr && root->right == nullptr;
        if (is_leaf) Update(cur_);
        
        if (root->left) Dfs(root->left);
        if (root->right) Dfs(root->right);
        
        cur_.pop_back();
    }
};
