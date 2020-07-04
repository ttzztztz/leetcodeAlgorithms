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
    bool isCompleteTree(TreeNode* root) {
        if (root == nullptr) return true;
        
        deque<TreeNode*> q = {root};
        while (!q.empty()) {
            TreeNode* u = q.front();
            q.pop_front();
            
            if (u == nullptr) break;
            
            q.push_back(u->left);
            q.push_back(u->right);
        }
        
        for (auto x : q) {
            if (x != nullptr) return false;
        }
        return true;
    }
};