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
    long long answer = 0;
    int sumNumbers(TreeNode* root) {
        if (root == nullptr) return 0;
        dfs(root, 0);
        return answer;
    }
private:
    void dfs(TreeNode* root, int u) {
        const bool isLeaf = !(root->left) && !(root->right);
        
        if (isLeaf) {
            answer += u * 10 + root->val;
            return;
        }
        
        if (root->left) dfs(root->left, u * 10 + root->val);
        if (root->right) dfs(root->right, u * 10 + root->val);
    }
};
