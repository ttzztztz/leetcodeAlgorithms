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
    int averageOfSubtree(TreeNode* root) {
        return get<0>(dfs(root));
    }
private:
    typedef tuple<int, int, int> State; // { ans, node_cnt, sum }
    State dfs(TreeNode* root) {
        if (root == nullptr) return { 0, 0, 0 };

        auto [ans_l, node_cnt_l, sum_l] = dfs(root->left);
        auto [ans_r, node_cnt_r, sum_r] = dfs(root->right);

        int node_cnt = node_cnt_l + node_cnt_r + 1;
        int sum = sum_l + sum_r + root->val;
        int ans = ans_l + ans_r;
        if (sum / node_cnt == root->val) ans++;
        return { ans, node_cnt, sum };
    }
};