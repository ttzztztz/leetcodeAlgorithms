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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder, this->inorder = inorder;
        const int n = inorder.size();
        return build(0, n - 1);
    }
private:
    vector<int> preorder, inorder;
    int ptr = 0;
    
    TreeNode* build(int l, int r) {
        if (l > r) return nullptr;
        TreeNode* root = new TreeNode(preorder[ptr]);
        ptr++;
        
        int i = l;
        for (; i <= r; i++) {
            if (inorder[i] == root->val) {
                break;
            }
        }
        root->left = build(l, i - 1);
        root->right = build(i + 1, r);
        return root;
    }
};