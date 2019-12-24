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
    vector<int> answer;
    void dfs(TreeNode* u) {
        if (u->left != nullptr) {
            dfs(u->left);
        }
        answer.push_back(u->val);
        if (u->right != nullptr) {
            dfs(u->right);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return vector<int>();
        }
        dfs(root);
        return answer;
    }
};