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
        traverse(root);
        swap($1->val, $2->val);
    }
private:
    vector<TreeNode*> result;
    TreeNode *$1 = nullptr, *$2 = nullptr;
    void traverse(TreeNode* root) {
        if (root == nullptr) return;
        
        traverse(root->left);
        if (!result.empty() && root->val < (*result.rbegin())->val) {
            if ($1 == nullptr) $1 = *result.rbegin();
            $2 = root;
        }
        result.push_back(root);
        traverse(root->right);
    }
};
