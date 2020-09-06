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
        find(root, p, path1);
        find(root, q, path2);
        
        TreeNode *prev = root;
        for (int i = 0; i < min(path1.size(), path2.size()); i++) {
            if (path1[i] != path2[i]) return prev;
            prev = path1[i];
        }
        return prev;
    }
private:
    bool find(TreeNode* u, TreeNode* target, vector<TreeNode*>& storage) {
        if (u == nullptr) return false;
        storage.push_back(u);
        
        if (u == target) return true;
        if (find(u->left, target, storage)) return true;
        if (find(u->right, target, storage)) return true;
        
        storage.pop_back();
        return false;
    }
};
