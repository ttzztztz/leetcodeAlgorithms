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
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        return dfs(root, arr, 0);
    }
private:
    bool dfs(TreeNode* root, vector<int>& arr, int index) {
        if (root == nullptr) return false;
        
        const bool isLeaf = root->left == nullptr && root->right == nullptr;
        if (index >= arr.size()) return false;
        if (root->val != arr[index]) return false;
        
        if (isLeaf) return index == arr.size() - 1;
        return dfs(root->left, arr, index + 1) || dfs(root->right, arr, index + 1);
    }
};
