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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for (int i = 0; i < postorder.size(); i++) post_idx[postorder[i]] = i;
        return dfs(preorder, postorder, 0, preorder.size() - 1, 0, postorder.size() - 1);
    }
private:
    unordered_map<int, int> post_idx;

    TreeNode* dfs(const vector<int>& pre, const vector<int>& post, int pre_left, int pre_right, int post_left, int post_right) {
        if (pre_left > pre_right || post_left > post_right) return nullptr;
        TreeNode* node = new TreeNode(pre[pre_left]);
        if (pre_left == pre_right || post_left == post_right) {
            return node;
        }

        int i = post_idx[pre[pre_left + 1]] - post_left;
        node->left = dfs(pre, post, pre_left + 1, pre_left + 1 + i, post_left, post_left + i);
        node->right = dfs(pre, post, pre_left + i + 2, pre_right, post_left + i + 1, post_right - 1);
        return node;
    }
};