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
        if (root == nullptr) return nullptr;
        return dfs(root).first;
    }
private:
    pair<TreeNode*, int> dfs(TreeNode* root) {
        if (root == nullptr) return {nullptr, 0};
        
        auto [l_root, l_dep] = dfs(root->left);
        auto [r_root, r_dep] = dfs(root->right);
        
        if (l_dep == r_dep) return { root, l_dep + 1 };
        else if (l_dep > r_dep) return { l_root, l_dep + 1 };
        else return { r_root, r_dep + 1 }; // l_dep < r_dep
    }
};
