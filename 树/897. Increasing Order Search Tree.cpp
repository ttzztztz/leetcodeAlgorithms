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
    TreeNode* increasingBST(TreeNode* root) {
        return dfs(root).first;
    }
private:
    typedef pair<TreeNode*, TreeNode*> State;
    State kEmptyState = {nullptr, nullptr};
    State dfs(TreeNode* root) {
        if (root == nullptr) return kEmptyState;
        State ans = {root, root};
        
        auto [l1, l2] = dfs(root->left);
        auto [r1, r2] = dfs(root->right);

        if (l2) l2->right = root;
        root->right = r1;
        root->left = nullptr;
        
        if (l1) ans.first = l1;
        if (r2) ans.second = r2;
        return ans;
    }
};
