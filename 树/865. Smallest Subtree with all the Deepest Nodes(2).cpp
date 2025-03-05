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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        dfs_depth(root, 0);
        return find_node(root, 0).first;
    }
private:
    int max_depth = -1, cnt = 0;

    pair<TreeNode*, int> find_node(TreeNode* root, int depth) {
        if (root == nullptr) return { nullptr, 0 };

        int base_cnt = (depth == max_depth) ? 1 : 0;
        auto [l_node, l_cnt] = find_node(root->left, depth + 1);
        auto [r_node, r_cnt] = find_node(root->right, depth + 1);

        if (l_node != nullptr) return { l_node, l_cnt };
        if (r_node != nullptr) return { r_node, r_cnt };
        if (l_cnt + r_cnt + base_cnt == cnt) return { root, l_cnt + r_cnt + base_cnt };

        return { nullptr, l_cnt + r_cnt + base_cnt };
    }

    void dfs_depth(TreeNode* root, int depth) {
        if (root == nullptr) return;

        if (depth > max_depth) {
            max_depth = depth;
            cnt = 0;
        }
        if (depth == max_depth) {
            cnt++;
        }

        dfs_depth(root->left, depth + 1);
        dfs_depth(root->right, depth + 1);
    }
};