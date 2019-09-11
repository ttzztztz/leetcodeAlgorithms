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
    bool compareNode(TreeNode* node1, TreeNode* node2) {
        if (node1 == nullptr || node2 == nullptr) {
            return node1 == node2;
        }

        if (node1->val != node2->val) {
            return false;
        } else {
            return compareNode(node1->left, node2->right) && compareNode(node1->right, node2->left);
        }

    }
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr || (root->left == root->right && root->left == nullptr)) {
            return true;
        } else {
            return compareNode(root->left, root->right);
        }
    }
};