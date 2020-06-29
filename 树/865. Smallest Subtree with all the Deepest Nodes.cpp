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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        dfs(root);
        vector<TreeNode*> cur = all;
        auto judge = [&]() -> bool {
            bool allSame = false;
            for (int i = 1; i < cur.size(); i++) {
                if (cur[i] != cur[i - 1]) return false;
            }
            return true;
        };
        
        while (!judge()) {
            for (int i = 0; i < cur.size(); i++) {
                cur[i] = prev[cur[i]];
            }
        }
        return cur[0];
    }
private:
    int dep = 0;
    vector<TreeNode*> all;
    unordered_map<TreeNode*, TreeNode*> prev;
    void dfs(TreeNode* u, int depth = 0) {
        if (u == nullptr) return;
        
        if (depth > dep) {
            dep = depth;
            all = {u};
        } else if (depth == dep) all.push_back(u);
        dfs(u->left, depth + 1);
        if (u->left) prev[u->left] = u;
        dfs(u->right, depth + 1);
        if (u->right) prev[u->right] = u;
    }
};