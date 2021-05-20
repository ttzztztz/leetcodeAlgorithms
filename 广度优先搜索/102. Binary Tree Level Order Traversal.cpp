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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        
        deque<TreeNode*> q = {root};
        while (!q.empty()) {
            ans.push_back(vector<int>{});
            const int cnt = q.size();
            for (int _ = 0; _ < cnt; _++) {
                const auto u = q.front();
                q.pop_front();
                
                ans.back().push_back(u->val);
                
                if (u->left) q.push_back(u->left);
                if (u->right) q.push_back(u->right);
            }
        }
        return ans;
    }
};