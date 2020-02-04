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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return vector<TreeNode*> {};
        }
        
        dp = vector<vector<vector<TreeNode*>>>(n + 5, vector<vector<TreeNode*>>(n + 5, vector<TreeNode*>{}));
        return dfs(1, n);
    }
private:
    vector<vector<vector<TreeNode*>>> dp;
    vector<TreeNode*> dfs(int left, int right) {
        if (dp[left][right].size() != 0) {
            return dp[left][right];
        }
        
        vector<TreeNode*> answer;
        if (left > right) {
            answer.push_back(nullptr);
            return answer;
        } else if (left == right) { 
            TreeNode* cur = new TreeNode(left);
            answer.push_back(cur);
            return answer;
        }
        
        for (int i = left; i <= right; i++) {
            vector<TreeNode*> l = dfs(left, i - 1);
            vector<TreeNode*> r = dfs(i + 1, right);
            
            for (int a = 0; a < l.size(); a++) {
                for (int b = 0; b < r.size(); b++) {
                    TreeNode* top = new TreeNode(i);
                    top->left = l[a], top->right = r[b];
                    answer.push_back(top);
                }
            }
        }
        return dp[left][right] = answer;
    }
};
