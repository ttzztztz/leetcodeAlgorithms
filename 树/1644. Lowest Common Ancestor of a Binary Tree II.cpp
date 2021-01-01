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
        dfs(root, p);
        path1 = cur;
        cur.clear();
        dfs(root, q);
        path2 = cur;
        cur.clear();
        
        TreeNode* last = nullptr;
        for (size_t i = 0; i < min(path1.size(), path2.size()); i++) {
            if (path1[i] != path2[i]) {
                return last;
            } else {
                last = path1[i];
            }
        }
        return last;
    }
private:
    vector<TreeNode*> cur, path1, path2;
    
    bool dfs(TreeNode* root, TreeNode* target) {
        if (root == nullptr) return false;
        cur.push_back(root);
        if (root == target) return true;
        
        if (dfs(root->left, target)) return true;
        if (dfs(root->right, target)) return true;
        cur.pop_back();
        return false;
    }
};
