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
    vector<TreeNode*> generateTrees(int n) {
        return build(1, n);
    }
private:
    unordered_map<string, vector<TreeNode*>> memo;

    string hash(int i, int j) {
        return to_string(i) + "," + to_string(j);
    }

    vector<TreeNode*> build(int l, int r) {
        if (l > r) return {};
        if (l == r) return { new TreeNode(l) };
        if (memo.count(hash(l, r))) return memo[hash(l, r)];

        vector<TreeNode*> ans;
        for (int u = l; u <= r; u++) {
            vector<TreeNode*> left_nodes = build(l, u - 1);
            vector<TreeNode*> right_nodes = build(u + 1, r);

            if (left_nodes.empty()) left_nodes.push_back(nullptr);
            if (right_nodes.empty()) right_nodes.push_back(nullptr);

            for (TreeNode* x : left_nodes) for (TreeNode* y : right_nodes) {
                ans.push_back(new TreeNode(u, x, y));
            }
        }
        return memo[hash(l, r)] = ans;
    }
};