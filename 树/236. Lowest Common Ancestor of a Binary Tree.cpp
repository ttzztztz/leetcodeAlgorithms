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
        vector<TreeNode*> path1, path2;
        dfs(root, p, path1);
        dfs(root, q, path2);
        
        for (int i = 0; i < min(path1.size(), path2.size()); i++) {
            if (path1[i] == path2[i]) continue;
            else return path1[i - 1];
        }
        return path1[min(path1.size(), path2.size()) - 1];
    }
private:
    bool dfs(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
        if (root == nullptr) return false;
        
        path.push_back(root);
        if (root == target) return true;

        if (dfs(root->left, target, path)) return true;
        if (dfs(root->right, target, path)) return true;
        path.pop_back();
        return false;
    }
};