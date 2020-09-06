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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        this->ino = inorder;
        this->posto = postorder;
        
        const int N = inorder.size();
        ptr = N - 1;
        return build(0, N - 1);
    }
private:
    vector<int> ino, posto;
    int ptr;
    TreeNode* build(int l, int r) {
        if (l > r) return nullptr;
        
        const int val = posto[ptr--];
        TreeNode* u = new TreeNode(val);
        
        int div = 0;
        for (int k = l; k <= r; k++) {
            if (ino[k] == val) {
                div = k;
                break;
            }
        }
        
        u->right = build(div + 1, r);
        u->left = build(l, div - 1);
        return u;
    }
};