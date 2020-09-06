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
    bool isCousins(TreeNode* root, int x, int y) {
        int depX = -1, depY = -1;
        TreeNode* parX = nullptr, * parY = nullptr;
        
        deque<TreeNode*> q;
        q.push_back(root);
        
        int layer = 0;
        while (!q.empty()) {
            int cnt = q.size();
            for (int _ = 0; _ < cnt; _++) {
                TreeNode* u = q.front();
                
                if (u->val == x) depX = layer;
                if (u->val == y) depY = layer;
                
                q.pop_front();
                
                if (u->left) {
                    q.push_back(u->left);
                    if (u->left->val == x) parX = u;
                    if (u->left->val == y) parY = u;
                }
                if (u->right) {
                    q.push_back(u->right);
                    if (u->right->val == x) parX = u;
                    if (u->right->val == y) parY = u;
                }
            }
            
            layer++;
        }
        
        return depX == depY && parX != parY;
    }
};
