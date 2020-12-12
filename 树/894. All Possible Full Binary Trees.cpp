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
    vector<TreeNode*> allPossibleFBT(int N) {
        if (N == 0) return {};
        return dfs(N);
    }
private:
    unordered_map<int, vector<TreeNode*>> memo_;
    
    vector<TreeNode*> dfs(int N) {
        if (N == 0) return {nullptr};
        else if (N == 1) return {new TreeNode(0)};
        else if (N == 2) return {};
        
        if (memo_.count(N)) return memo_[N];
        
        vector<TreeNode*> ans;
        for (int left_size = 1; left_size <= N - 1 && N - left_size - 1 >= 1; left_size++) {
            const int right_size = N - left_size - 1;
            vector<TreeNode*> l = dfs(left_size);
            vector<TreeNode*> r = dfs(right_size);
            
            for (auto a : l) {
                for (auto b : r) {
                    TreeNode* _root = new TreeNode(0);
                    _root->left = a, _root->right = b;
                    ans.push_back(_root);
                }
            }
        }
        return memo_[N] = ans;
    }
};
