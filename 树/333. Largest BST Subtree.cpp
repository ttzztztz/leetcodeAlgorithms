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
    int largestBSTSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
private:
    int ans = 0;

    // { node_cnt, min, max, is_bst }
    tuple<int, int, int, bool> dfs(TreeNode* root) {
        if (root == nullptr) return { 0, numeric_limits<int>::max(), numeric_limits<int>::min(), true };

        auto [node_cnt_l, min_l, max_l, is_bst_l] = dfs(root->left);
        auto [node_cnt_r, min_r, max_r, is_bst_r] = dfs(root->right);
        
        bool is_bst = false;
        if (is_bst_l && is_bst_r && max_l < root->val && root->val < min_r) {
            ans = max(ans, 1 + node_cnt_l + node_cnt_r);
            is_bst = true;
        }

        return { 1 + node_cnt_l + node_cnt_r, min(root->val, min(min_l, min_r)), max(root->val, max(max_l, max_r)), is_bst };
    }
};