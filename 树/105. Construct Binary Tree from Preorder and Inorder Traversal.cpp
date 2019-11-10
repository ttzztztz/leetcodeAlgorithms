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
    int pre_index;
    void build(TreeNode* root, vector<int>& preorder, vector<int>& inorder, int dir, int in_start, int in_end) {
        if (in_start > in_end) {
            return;
        }

        const int val = preorder[pre_index++];
        TreeNode* nextRoot = root;
        if (dir == 0) {
            root->left = new TreeNode(val);
            nextRoot = root->left;
        } else {
            root->right = new TreeNode(val);
            nextRoot = root->right;
        }

        int in_offset = std::find(inorder.begin() + in_start, inorder.begin() + in_end, val) - inorder.begin();
        build(nextRoot, preorder, inorder, 0, in_start, in_offset - 1);
        build(nextRoot, preorder, inorder, 1, in_offset + 1, in_end);
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        const int N = preorder.size();
        if (N == 0) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[0]);
        pre_index = 1;
        int in_offset = std::find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();
        build(root, preorder, inorder, 0, 0, in_offset - 1);
        build(root, preorder, inorder, 1, in_offset + 1, N - 1);
        return root;
    }
};