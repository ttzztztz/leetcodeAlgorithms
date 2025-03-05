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
        if (root == nullptr) return {};
        typedef tuple<int, int, int> Data; // (col, row, val)
        typedef tuple<TreeNode*, int, int> State; // (node, row, col)

        deque<State> q = { { root, 0, 0 } };
        vector<Data> data;
        while (!q.empty()) {
            auto [node, row, col] = q.front();
            data.emplace_back(col, row, node->val);
            q.pop_front();

            if (node->left) q.emplace_back(node->left, row + 1, col - 1);
            if (node->right) q.emplace_back(node->right, row + 1, col + 1);
        }

        sort(data.begin(), data.end());
        vector<vector<int>> ans;
        for (int i = 0; i < data.size(); i++) {
            auto [col, row, val] = data[i];
            vector<int> tmp = { val };
            while (i + 1 < data.size() && get<0>(data[i + 1]) == col) {
                tmp.push_back(get<2>(data[i + 1]));
                i++;
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};