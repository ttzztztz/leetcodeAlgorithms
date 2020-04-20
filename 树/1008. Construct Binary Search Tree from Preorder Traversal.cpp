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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        const int N = preorder.size();
        return build(preorder, 0, N - 1);
    }
private:
    TreeNode* build(const vector<int>& preorder, const int left, const int right) {
        if (left == right) return new TreeNode(preorder[left]);
        else if (left > right) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[left]);
        int ptr = left + 1;
        while (ptr <= right && preorder[ptr] < preorder[left]) ptr++;
        
        root->left = build(preorder, left + 1, ptr - 1);
        root->right = build(preorder, ptr, right);
        
        return root;
    }
};
