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
    int rangeSumBST(TreeNode* root, int low, int high) {
        this->l = low, this->r = high;
        dfs(root);
        return ans;
    }
private:
    int l, r;
    int ans = 0;
    void dfs(TreeNode* u) {
        if (u == nullptr) return;
        
        if (u->val < l) {
            dfs(u->right);
        } else if (r < u->val) {
            dfs(u->left);
        } else {
            ans += u->val;
            dfs(u->left), dfs(u->right);
        }
    }
};
