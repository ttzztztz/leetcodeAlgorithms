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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.empty()) return nullptr;
        return build(preorder, 0, preorder.size() - 1);
    }
private:
    TreeNode* build(const vector<int>& data, int l, int r) {
        if (l > r) return nullptr;
        TreeNode* cur = new TreeNode(data[l]);
        if (l == r) return cur;

        int k = l + 1;
        while (k <= r && data[l] > data[k]) k++;
        cur->left = build(data, l + 1, k - 1);
        cur->right = build(data, k, r);
        return cur;
    }
};