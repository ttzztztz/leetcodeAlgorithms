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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        auto p = dfs(root, 0, limit);
        
        if (p) return nullptr;
        return root;
    }
private:
    bool dfs(TreeNode* u, int sum, const int limit) {
        if (u == nullptr) return true;
        
        const bool isLeaf = u->left == nullptr && u->right == nullptr;
        if (isLeaf) {
            if (sum + u->val >= limit) return false;
            else return true;
        } else {
            if (dfs(u->left, sum + u->val, limit)) u->left = nullptr;
            if (dfs(u->right, sum + u->val, limit)) u->right = nullptr;
            
            if (u->left == nullptr && u->right == nullptr) return true;
        }
        
        return false;
    }
};
