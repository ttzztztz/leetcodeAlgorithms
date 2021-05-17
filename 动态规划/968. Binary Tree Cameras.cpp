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
    int minCameraCover(TreeNode* root) {
        if (root == nullptr) return 0;
        memset(f, 0x3f, sizeof f);
        f[0][0] = 0;
        f[0][1] = f[0][2] = 0x3f3f3f3f;
        
        dfs(root);
        // for (int i = 1; i <= 5; i++) {
        //     cout << f[i][0] << " " << f[i][1] << " " << f[i][2] << endl;
        // }
        return min(f[1][0], f[1][2]);
    }
private:
    unordered_map<TreeNode*, int> id;
    int f[1005][3];
    // 0 -> place light
    // 1 -> not place, from parent
    // 2 -> not place, from child
    int cnt = 0;
    
    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        id[root] = ++cnt;
        
        if (root->left) dfs(root->left);
        if (root->right) dfs(root->right);
        
        const int u = id[root], l = id[root->left], r = id[root->right];
        if (!root->left && !root->right) {
            f[u][0] = 1;
            f[u][1] = 0;
            f[u][2] = 1005;
            return;
        }
        
        for (int i = 0; i <= 2; i++) for (int j = 0; j <= 2; j++) {
            f[u][0] = min(f[u][0],
                          f[l][i] + f[r][j] + 1);
        }
        
        f[u][1] = min(
            min(f[l][0] + f[r][0], f[l][2] + f[r][2]),
            min(f[l][0] + f[r][2], f[l][2] + f[r][0])
        );
        
        f[u][2] = f[l][0] + f[r][0];
        if (root->left) f[u][2] = min(f[u][2], f[l][0] + f[r][2]);
        if (root->right) f[u][2] = min(f[u][2], f[l][2] + f[r][0]);
    }
};