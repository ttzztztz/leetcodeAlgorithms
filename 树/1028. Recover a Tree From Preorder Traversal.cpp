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
    TreeNode* recoverFromPreorder(string S) {
        this->s_ = S;
        this->idx = 0;
        return dfs(0);
    }
private:
    int idx;
    string s_;
    
    TreeNode* dfs(int depth) {
        if (idx == s_.size()) return nullptr;
        int i = idx;
        int cur_dep = 0;
        for (; i < s_.size(); i++) {
            if (s_[i] == '-') cur_dep++;
            else break;
        }
        if (cur_dep != depth) return nullptr;
        
        idx = i;
        int val = 0;
        for (; i < s_.size(); i++) {
            if (s_[i] == '-') break;
            val = val * 10 + (s_[i] - '0');
        }
        TreeNode* root = new TreeNode(val);
        idx = i;
        
        root->left = dfs(depth + 1);
        root->right = dfs(depth + 1);
        return root;
    }
};
