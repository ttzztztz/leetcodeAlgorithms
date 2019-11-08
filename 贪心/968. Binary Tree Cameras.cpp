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
    int minCameraCover(TreeNode* root) {
        answer = 0;
        if (dfs(root) == 0) {
            answer++;
        }
        return answer;
    }

    int dfs(TreeNode *node) {
        if (node == nullptr) {
            return -1;
        }
        int left = dfs(node->left), right = dfs(node->right);
        if (left == 0 || right == 0) {
            answer++;
            return 1;
        }
        if (left == 1 || right == 1) {
            return -1;
        }

        return 0;
    }
};