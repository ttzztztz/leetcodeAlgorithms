/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param root: The root of the binary search tree.
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode * removeNode(TreeNode * root, int val) {
        if (root == nullptr) return nullptr;
        
        if (root ->val == val) {
            if (root->left) {
                TreeNode* cur = root->left;
                while (cur->right) {
                    cur = cur->right;
                }
                root->val = cur->val;
                root->left = removeNode(root->left, cur->val);
            } else if (root->right) {
                TreeNode* cur = root->right;
                while (cur->left) {
                    cur = cur->left;
                }
                root->val = cur->val;
                root->right = removeNode(root->right, cur->val);
            } else return nullptr;
        } else if (root->val < val) {
            root->right = removeNode(root->right, val);
        } else if (val < root->val) {
            root->left = removeNode(root->left, val);
        }
        
        return root;
    }
};
