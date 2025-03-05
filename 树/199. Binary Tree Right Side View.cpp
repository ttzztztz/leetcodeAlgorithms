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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
        dfs(root, 1);

        return ans;
    }
private:
    vector<int> ans;

    void dfs(TreeNode* root, int layer) {
        if (root == nullptr) return;

        if (ans.size() < layer) ans.push_back(root->val);
        dfs(root->right, layer + 1);
        dfs(root->left, layer + 1);
    }
};