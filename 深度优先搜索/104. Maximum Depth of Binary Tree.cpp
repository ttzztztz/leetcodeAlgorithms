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
    int answer;
    void dfs(TreeNode* node, int height) {
        answer = std::max(answer, height);
        if(node != nullptr) {
            dfs(node->left, height + 1);
            dfs(node->right, height + 1);
        }
    }

    int maxDepth(TreeNode* root) {
        answer = 0;
        dfs(root, 0);
        return answer;
    }
};