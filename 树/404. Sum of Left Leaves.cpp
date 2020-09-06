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
    int sumOfLeftLeaves(TreeNode* root) {
        dfs(root, -1);
        return sum;
    }
private:
    int sum = 0;
    void dfs(TreeNode* u, int dir) {
        if (u == nullptr) return;
        if (u->left == nullptr && u->right == nullptr) { // l
            if (dir == 1) sum += u->val;
            return;
        }
        
        dfs(u->left, 1);
        dfs(u->right, 0);
    }
};