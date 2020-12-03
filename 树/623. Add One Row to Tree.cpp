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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode* new_root = new TreeNode(v);
            new_root->left = root;
            return new_root;
        }
        
        vector<TreeNode*> d_nodes;
        deque<TreeNode*> q = {root};
        int layer = 1;
        while (!q.empty()) {
            const int t = q.size();
            for (int _ = 0; _ < t; _++) {
                TreeNode* u = q.front();
                q.pop_front();
                
                if (d - 1 == layer) {
                    d_nodes.push_back(u);
                }
                
                if (u->left) q.push_back(u->left);
                if (u->right) q.push_back(u->right);
            }
            layer++;
        }
        
        for (TreeNode* u : d_nodes) {
            TreeNode* new_left = new TreeNode(v);
            new_left->left = u->left;
            u->left = new_left;
            
            TreeNode* new_right = new TreeNode(v);
            new_right->right = u->right;
            u->right = new_right;
        }
        return root;
    }
};
