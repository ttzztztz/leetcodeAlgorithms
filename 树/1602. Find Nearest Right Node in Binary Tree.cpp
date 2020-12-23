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
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* target) {
        if (root == nullptr) return nullptr;
        
        deque<TreeNode*> q = {root};
        int layer = 0;
        while (!q.empty()) {
            const int cnt = q.size();
            bool return_next = false;
            for (int _ = 0; _ < cnt; _++) {
                TreeNode* u = q.front();
                if (u == target) return_next = true;
                else if (return_next) return u;
                
                q.pop_front();
                
                if (u->left) q.push_back(u->left);
                if (u->right) q.push_back(u->right);
            }
            
            if (return_next) { // no right node
                return nullptr;
            }
        }
        return nullptr; // not found
    }
};
