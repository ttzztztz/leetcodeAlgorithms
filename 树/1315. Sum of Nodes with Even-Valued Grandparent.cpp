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
    int answer = 0;
    void dfs(TreeNode* u, TreeNode* parent, TreeNode* grandParent) {
        if (grandParent != nullptr && grandParent->val % 2 == 0) {
            answer += u->val;
        }
        if (u->left) {
            dfs(u->left, u, parent);
        }
        if (u->right) {
            dfs(u->right, u, parent);
        }
    }
    int sumEvenGrandparent(TreeNode* root) {
        dfs(root, nullptr, nullptr);
        return answer;
    }
};
