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
    bool isEvenOddTree(TreeNode* root) {
        vector<vector<int>> all;
        int layer = 0;
        deque<TreeNode*> q = {root};
        while (!q.empty()) {
            all.push_back(vector<int>{});
            const int cnt = q.size();
            for (int _ = 0; _ < cnt; _++) {
                TreeNode* u = q.front();
                q.pop_front();
                all[layer].push_back(u->val);
                
                if (u->left) q.push_back(u->left);
                if (u->right) q.push_back(u->right);
            }
            layer++;
        }
        
        for (int i = 0; i < all.size(); i++) {
            for (int j = 1; j < all[i].size(); j++) {
                if (i % 2 == 1 && all[i][j - 1] <= all[i][j]) return false;
                if (i % 2 == 0 && all[i][j - 1] >= all[i][j]) return false;
            }
            
            for (int j = 0; j < all[i].size(); j++) {
                if (i % 2 == 1 && all[i][j] % 2 == 1) return false;
                if (i % 2 == 0 && all[i][j] % 2 == 0) return false;
            }
        }
        return true;
    }
};
