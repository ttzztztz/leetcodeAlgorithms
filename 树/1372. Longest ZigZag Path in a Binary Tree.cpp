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
    int longestZigZag(TreeNode* root) {
        deque<TreeNode*> q;
        q.push_back(root);
        
        int answer = 0;
        while (!q.empty()) {
            TreeNode* u = q.front();
            q.pop_front();
            
            answer = max(answer, max(dfs(u, 0) - 1, dfs(u, 1) - 1));
            if (u->left) q.push_back(u->left);
            if (u->right) q.push_back(u->right);
        }
        return answer;
    }
    unordered_map<TreeNode*, int> dp[2];
    int dfs(TreeNode* u, int dir) {
        if (u == nullptr) return 0;
        if (dp[dir].count(u)) return dp[dir][u];
        
        int answer = 1;
        if (dir == 0) {
            answer += dfs(u->left, dir ^ 1);
        } else {
            answer += dfs(u->right, dir ^ 1);
        }
        
        return dp[dir][u] = answer;
    }
    
};
