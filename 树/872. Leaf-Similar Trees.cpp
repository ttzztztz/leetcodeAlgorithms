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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs(v1, root1);
        dfs(v2, root2);
        return v1 == v2;
    }
private:
    vector<int> v1, v2;
    void dfs(vector<int>& v, TreeNode* u) {
        if (u == nullptr) return;
        
        if (u->left == nullptr && u->right == nullptr) {
            v.push_back(u->val);
            return;
        }
        dfs(v, u->left);
        dfs(v, u->right);
    }
};