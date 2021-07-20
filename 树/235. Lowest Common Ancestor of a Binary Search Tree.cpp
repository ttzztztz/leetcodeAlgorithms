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
        
        if (path1.empty() || path2.empty()) return nullptr;
        for (int i = min(path1.size(), path2.size()) - 1; i >= 0; i--) {
            if (path1[i] == path2[i]) {
                return path1[i];
            }
        }
        return path1[min(path1.size(), path2.size()) - 1];
    }
private:
    bool dfs(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
        if (root == nullptr) return false;
        
        path.push_back(root);
        if (root == target) return true;
        
        if (root->val < target->val) {
            if (dfs(root->right, target, path)) return true;
        } else if (root->val == target->val) {
            return true;
        } else { // root->val > target->val
            if (dfs(root->left, target, path)) return true;
        }
        path.pop_back();
        return false;
    }
};