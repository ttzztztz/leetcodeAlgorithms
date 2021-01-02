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
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        if (root == nullptr) return nullptr;
        queries = unordered_set<TreeNode*>(nodes.begin(), nodes.end());
        dfs(root);
        return ans;
    }
private:
    unordered_set<TreeNode*> queries;
    TreeNode* ans;
    int dfs(TreeNode* u) {
        if (u == nullptr) return 0;
        
        size_t match = queries.count(u) + dfs(u->left) + dfs(u->right);
        if (match == queries.size() && ans == nullptr) {
             ans = u;
        }
        return match;
    }
};
