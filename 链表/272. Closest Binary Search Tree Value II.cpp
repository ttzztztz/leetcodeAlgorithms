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
    int closestValue(TreeNode* root, double target) {
        if (root == nullptr) return 0;
        int result = numeric_limits<int>::min();
        
        TreeNode* cur = root;
        while (cur != nullptr) {
            const int val = cur->val;

            if (abs(result - target) > abs(val - target)
                || (abs(result - target) == abs(val - target) && val < result)) {
                result = val;
            }

            if (val < target) {
                cur = cur->right;
            } else {
                cur = cur->left;
            }
        }
        return result;
    }
};