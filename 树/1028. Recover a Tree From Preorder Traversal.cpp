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
    TreeNode* recoverFromPreorder(string traversal) {
        if (traversal.empty()) return nullptr;
        vector<pair<int, int>> records = parse_string(traversal);
        return dfs(records, 0);
    }
private:
    int idx = 0;

    TreeNode* dfs(const vector<pair<int, int>>& records, int depth) {
        if (idx >= records.size()) return nullptr;
        const auto [cur_depth, val] = records[idx];
        if (cur_depth != depth) return nullptr;
        idx++;

        TreeNode* cur = new TreeNode(val);
        cur->left = dfs(records, depth + 1);
        cur->right = dfs(records, depth + 1);
        return cur;
    }

    vector<pair<int, int>> parse_string(const string& str) {
        vector<pair<int, int>> ans;
        const int n = str.size();
        for (int i = 0; i < n; i++) {
            int depth = 0;
            if (str[i] == '-') {
                depth = 1;
                while (i + 1 < n && str[i + 1] == '-') {
                    i++, depth++;
                }
                i++;
            }

            int val = str[i] - '0';
            while (i + 1 < n && '0' <= str[i + 1] && str[i + 1] <= '9') {
                val = val * 10 + str[i + 1] - '0';
                i++;
            }
            ans.push_back({ depth, val });
        }
        return ans;
    }
};