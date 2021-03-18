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
        vector<int> ans;
        
        if (root == nullptr) return ans;
        vector<pair<int, TreeNode*>> stk = {{0, root}};
        while (!stk.empty()) {
            auto [color, u] = stk.back();
            stk.pop_back();
            
            if (color == 0) {
                stk.emplace_back(1, u);
                if (u->right) stk.emplace_back(0, u->right);
                if (u->left) stk.emplace_back(0, u->left);
            } else { // color == 1
                ans.push_back(u->val);
            }
        }
        return ans;
    }
};
