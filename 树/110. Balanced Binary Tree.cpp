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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        return height(root) >= 0;
    }
private:
    int height(TreeNode* u) {
        if (u == nullptr) return 0;
        
        const int l = height(u->left), r = height(u->right);
        if (l == -1 || r == -1 || abs(l - r) > 1) return -1;
        else return 1 + max(l, r);
    }
};
