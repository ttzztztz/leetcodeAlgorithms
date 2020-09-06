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
    int maxValue, minValue;
    void dfs(TreeNode* root) {
        const int prevMax = maxValue, prevMin = minValue;
        
        maxValue = max(maxValue, root->val);
        minValue = min(minValue, root->val);
        
        if (root->left == nullptr && root->right == nullptr) {
            answer = max(answer, maxValue - minValue);
        }
        if (root->left) {
            dfs(root->left);
        }
        if (root->right) {
            dfs(root->right);
        }
        maxValue = prevMax, minValue = prevMin;
    }
    int maxAncestorDiff(TreeNode* root) {
        maxValue = minValue = root->val;
        dfs(root);
        return answer;
    }
};
