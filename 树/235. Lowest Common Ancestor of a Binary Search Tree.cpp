/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, path1);
        dfs(root, q, path2);
        
        int ptr = 0;
        const int N = path1.size(), M = path2.size();
        while (ptr < min(N, M)) {
            if (path1[ptr] == path2[ptr]) {
                ptr++;
            } else {
                return path1[ptr - 1];
            }
        }
        
        return path1[ptr - 1];
    }
private:
    vector<TreeNode*> path1, path2;
    bool dfs(TreeNode* u, const TreeNode* target, vector<TreeNode*>& path) {
        if (u == nullptr) return false;
        
        path.push_back(u);
        if (u == target) return true;
        if (dfs(u->left, target, path)) return true;
        if (dfs(u->right, target, path)) return true;
        path.pop_back();
        return false;
    }
};