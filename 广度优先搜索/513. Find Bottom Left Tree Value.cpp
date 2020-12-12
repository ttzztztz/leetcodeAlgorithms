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
    int findBottomLeftValue(TreeNode* root) {
        int ans = 0, layer = 0, last_layer = -1;
        
        deque<TreeNode*> q = {root};
        while (!q.empty()) {
            const int cnt = q.size();
            for (int _ = 0; _ < cnt; _++) {
                TreeNode* t = q.front();
                q.pop_front();
                
                if (last_layer != layer) {
                    last_layer = layer;
                    ans = t->val;
                }
                
                if (t->left) q.push_back(t->left);
                if (t->right) q.push_back(t->right);
            }
            layer++;
        }
        
        return ans;
    }
};
