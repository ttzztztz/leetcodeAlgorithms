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
    TreeNode* balanceBST(TreeNode* root) {
        if (root == nullptr) return nullptr;

        dfs(root);
        return build(0, data.size() - 1);
    }
private:
    vector<int> data;

    void dfs(TreeNode* root) {
        if (root == nullptr) return;

        dfs(root->left);
        data.push_back(root->val);
        dfs(root->right);
    }

    TreeNode* build(int l, int r) {
        if (l > r) return nullptr;

        const int mid = (l + r) / 2;
        TreeNode* root = new TreeNode(data[mid]);
        if (l == r) return root;

        root->left = build(l, mid - 1);
        root->right = build(mid + 1, r);
        return root;
    }
};