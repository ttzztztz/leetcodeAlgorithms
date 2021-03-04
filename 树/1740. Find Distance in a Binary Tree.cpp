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
    int findDistance(TreeNode* root, int p, int q) {
        vector<TreeNode*> p1, p2;

        dfs(root, p, p1);
        dfs(root, q, p2);
        
        int ptr = 0;
        while (ptr < min(p1.size(), p2.size())) {
            if (p1[ptr] == p2[ptr]) {
                ptr++;
            } else {
                break;
            }
        }
        return p1.size() + p2.size() - 2 * ptr;
    }
private:
    bool dfs(TreeNode* root, int target, vector<TreeNode*>& path) {
        path.push_back(root);
        
        if (root->val == target) {
            return true;
        }
        
        if (root->left && dfs(root->left, target, path)) return true;
        if (root->right && dfs(root->right, target, path)) return true;
        
        path.pop_back();
        return false;
    }
};
