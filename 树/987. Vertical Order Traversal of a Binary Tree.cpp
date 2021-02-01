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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        
        typedef tuple<TreeNode*, int, int> State;
        deque<State> q = { { root, 0, 0 } };
        
        typedef pair<int, int> PII;
        map<int, multiset<PII>> f;

        while (!q.empty()) {
            const int cnt = q.size();
            for (int _ = 0; _ < cnt; _++) {
                auto [node, x, y] = q.front();
                q.pop_front();
                
                f[y].emplace(x, node->val);
                if (node->left) q.emplace_back(node->left, x + 1, y - 1);
                if (node->right) q.emplace_back(node->right, x + 1, y + 1);
            }
        }
        
        for (auto& [k, x] : f) {
            ans.push_back({});
            for (auto& [_, val] : x) {
                ans.back().push_back(val);
            }
        }
        return ans;
    }
};
