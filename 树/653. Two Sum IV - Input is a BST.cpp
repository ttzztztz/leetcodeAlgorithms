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
    bool findTarget(TreeNode* root, int k) {
        return dfs(root, k);
    }
private:
    unordered_set<int> f;
    bool dfs(TreeNode* u, const int k) {
        if (u == nullptr) return false;
        
        if (f.count(k - u->val)) return true;
        f.insert(u->val);

        if (u->left && dfs(u->left, k)) return true;
        if (u->right && dfs(u->right, k)) return true;
        return false;
    }
};
