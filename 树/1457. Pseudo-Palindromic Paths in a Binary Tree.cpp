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
    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root);
        return ans;
    }
private:
    int ans = 0;
    unordered_map<int, int> appear;
    
    bool is_palindrome() {
        bool odd = false;
        for (auto& [k, v] : appear) {
            if (v % 2 == 1) {
                if (odd) return false;
                else odd = true;
            }
        }
        return true;
    }
    
    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        
        appear[root->val]++;
        if (root->left == nullptr && root->right == nullptr) {
            if (is_palindrome()) ans++;
        } else {
            dfs(root->left);
            dfs(root->right);
        }
        appear[root->val]--;
    }
};