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
    int countPairs(TreeNode* root, int distance) {
        this->dist = distance;
        dfs(root);
        return answer;
    }
private:
    int dist = 0, answer = 0;
    vector<int> dfs(TreeNode* u) {
        vector<int> cur(11, 0);
        if (u == nullptr) return cur;
        
        if (!u->left && !u->right) {
            cur[1] = 1;
            return cur;
        }
        
        vector<int> f = dfs(u->left), g = dfs(u->right);
        
        for (int i = 0; i <= dist; i++) {
            for (int j = 0; j <= dist; j++) {
                if (i + j <= dist) answer += f[i] * g[j];
            }
        }
        
        for (int i = 1; i <= dist; i++) {
            cur[i] += f[i - 1] + g[i - 1];
        }
        
        return cur;
    }
};
