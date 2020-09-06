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
    bool isValidBST(TreeNode* root) {
        traverse(root);
        
        for (int i = 1; i < it.size(); i++) {
            if (it[i] <= it[i - 1]) return false;
        }
        return true;
    }
private:
    void traverse(TreeNode* root) {
        if (root == nullptr) return;
        
        traverse(root->left);
        it.push_back(root->val);
        traverse(root->right);
    }
    vector<int> it;
};
