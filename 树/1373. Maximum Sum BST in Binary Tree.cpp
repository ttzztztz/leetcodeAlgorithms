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
    int maxSumBST(TreeNode* root) {
        dfs1(root);
        dfs2(root, -INF, INF);
        return answer;
    }
public:
    int INF = 1e5;
    long long answer = 0;
    unordered_map<TreeNode*, long long> sum;
    long long dfs1(TreeNode* u) { // get sum
        if (u == nullptr) return 0;
        
        long long answer = u->val;
        if (u->left) answer += dfs1(u->left);
        if (u->right) answer += dfs1(u->right);
        return sum[u] = answer;
    }
    bool dfs2(TreeNode* u, int left, int right) {
        bool isBST = true;
        if (u->left) {
            if (u->left->val >= u->val) {
                isBST = false;
                dfs2(u->left, -INF, INF);
            } else {
                bool b1 = dfs2(u->left, left, u->val - 1);
                isBST = isBST && b1;
            }
        }
        if (u->right) {
            if (u->right->val <= u->val) {
                isBST = false;
                dfs2(u->right, -INF, INF);
            } else {
                bool b2 = dfs2(u->right, u->val + 1, right);
                isBST = isBST && b2;
            }
        }
        
        if (isBST) answer = max(answer, sum[u]);
        return isBST;
    }
};
