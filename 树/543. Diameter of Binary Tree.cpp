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
    int diameterOfBinaryTree(TreeNode* root) {
        answer = 0;
        depth(root);
        return answer;
    }
    int depth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = depth(root->left), right = depth(root->right);
        answer = max(answer, left + right);
        return max(left, right) + 1;
    }
};