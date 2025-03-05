/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        return get<0>(dfs(root, p, q));
    }
private:
    tuple<TreeNode*, bool, bool> dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return { nullptr, false, false };

        auto [l_ans, l_p_find, l_q_find] = dfs(root->left, p, q);
        auto [r_ans, r_p_find, r_q_find] = dfs(root->right, p, q);

        if (l_ans != nullptr) return { l_ans, true, true };
        if (r_ans != nullptr) return { r_ans, true, true };

        const bool p_find = l_p_find || r_p_find || root == p;
        const bool q_find = l_q_find || r_q_find || root == q;

        if (p_find && q_find) return { root, true, true };

        return { nullptr, p_find, q_find };
    }
};