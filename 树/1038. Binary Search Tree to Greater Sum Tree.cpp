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
    TreeNode* bstToGst(TreeNode* root) {
        return dfs(root);
    }
private:
    int sum = 0;
    TreeNode* dfs(TreeNode* root) {
        if (root == nullptr) return nullptr;
        
        dfs(root->right);
        const int prev = root->val;
        root->val += sum;
        sum += prev;
        dfs(root->left);
        return root;
    }
};
