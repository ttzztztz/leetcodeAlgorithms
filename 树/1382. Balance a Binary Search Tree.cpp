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
    TreeNode* balanceBST(TreeNode* root) {
        traverse(root);
        const int N = data.size();
        return build(0, N - 1);
    }
private:
    vector<TreeNode*> data;
    void traverse(TreeNode* u) {
        if (u == nullptr) return;
        
        traverse(u->left);
        data.push_back(u);
        traverse(u->right);
    }
    TreeNode* build(int left, int right) {
        if (left > right) return nullptr;
        const int mid = (left + right) / 2;
        
        TreeNode* parent = data[mid];
        parent->left = build(left, mid - 1);
        parent->right = build(mid + 1, right);
        return parent;
    }
};
