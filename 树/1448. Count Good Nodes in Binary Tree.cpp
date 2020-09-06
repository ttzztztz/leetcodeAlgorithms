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
    int goodNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        dfs(root, root->val);
        return answer;
    }
private:
    int answer = 0;
    void dfs(TreeNode* u, int val) {
        if (u == nullptr) return;
        
        if (u->val >= val) {
            answer++;
        }
        
        dfs(u->left, max(val, u->val));
        dfs(u->right, max(val, u->val));
    }
};
