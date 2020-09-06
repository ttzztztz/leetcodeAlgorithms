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
    int pathSum(TreeNode* root, int t) {
        if (root == nullptr) return 0;
        this->t = t;
        f[0] = 1;
        return dfs(root, 0);
    }
private:
    unordered_map<int, int> f;
    int t;
    int dfs(TreeNode* u, int sum) {
        const int cur = u->val + sum;
        int answer = 0;
        if (f.count(cur - t)) answer += f[cur - t];
        
        f[cur]++;
        if (u->left) answer += dfs(u->left, cur);
        if (u->right) answer += dfs(u->right, cur);
        
        f[cur]--;
        if (f[cur] == 0) f.erase(cur);
        return answer;
    }
};