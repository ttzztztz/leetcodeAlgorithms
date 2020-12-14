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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return dfs(cloned, target->val);
    }
private:
    TreeNode* dfs(TreeNode* u, int val) {
        if (u == nullptr) return nullptr;
        if (u->val == val) return u;
        
        TreeNode* l = dfs(u->left, val);
        if (l) return l;
        TreeNode* r = dfs(u->right, val);
        if (r) return r;
        
        return nullptr; // not found
    }
};
