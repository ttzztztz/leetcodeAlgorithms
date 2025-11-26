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
            const int n = q.size();
            vector<int> layer;
            for (int _ = 0; _ < n; _++) {
                TreeNode* cur = q.front();
                q.pop_front();

                layer.push_back(cur->val);

                if (cur->left) q.push_back(cur->left);
                if (cur->right) q.push_back(cur->right);
            }
            ans.push_back(layer);
        }

        return ans;
    }
};