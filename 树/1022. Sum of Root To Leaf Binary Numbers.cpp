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
    int sumRootToLeaf(TreeNode* root) {
        dfs(root, 0);
        return answer;
    }
private:
    int answer = 0;
    void dfs(TreeNode* u, int val) {
        if (u == nullptr) return;
        
        const bool leaf = u->left == nullptr && u->right == nullptr;
        if (leaf) {
            answer += (val << 1) | u->val;
            return;
        }
        
        dfs(u->left, (val << 1) | u->val);
        dfs(u->right, (val << 1) | u->val);
    }
};