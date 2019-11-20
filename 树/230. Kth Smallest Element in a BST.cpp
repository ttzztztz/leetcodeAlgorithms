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
    int answer, K;
    void inorderTraverse(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        if (answer != -1) {
            return;
        }

        inorderTraverse(root->left);
        K--;
        if (K == 0) {
            answer = root->val;
        }
        inorderTraverse(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        answer = -1, K = k;

        inorderTraverse(root);
        return answer;
    }
};