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
    void recoverTree(TreeNode* root) {
        TreeNode* a = nullptr, *b = nullptr;
        
        TreeNode* cur = root, *prev = nullptr;
        while (cur) {
            if (cur->left) {
                TreeNode* t = cur->left;
                while (t->right != nullptr && t->right != cur) t = t->right;
                if (t->right == nullptr) {
                    t->right = cur;
                    cur = cur->left;
                } else if (t->right == cur) {
                    t->right = nullptr;

                    if (prev && cur->val < prev->val) {
                        if (a == nullptr) a = prev;
                        b = cur;
                    }
                    
                    prev = cur;
                    cur = cur->right;
                }
            } else {
                if (prev && cur->val < prev->val) {
                    if (a == nullptr) a = prev;
                    b = cur;
                }
                
                prev = cur;
                cur = cur->right;
            }
        }
        
        swap(a->val, b->val);
    }
};
