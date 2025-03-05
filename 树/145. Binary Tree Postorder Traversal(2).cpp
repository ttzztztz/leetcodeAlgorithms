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
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};

        vector<pair<TreeNode*, bool>> stk = { { root, false } };
        vector<int> ans;
        while (!stk.empty()) {
            auto [node, visited] = stk.back();
            stk.pop_back();

            if (visited) {
                ans.push_back(node->val);
            } else {
                // left right root
                stk.emplace_back(node, true);
                if (node->right) stk.emplace_back(node->right, false);
                if (node->left) stk.emplace_back(node->left, false);
            }
        }
        return ans;
    }
};