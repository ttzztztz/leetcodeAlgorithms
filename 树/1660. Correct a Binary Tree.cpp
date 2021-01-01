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
    TreeNode* correctBinaryTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        layer.clear();
        int cur = 0;
        deque<TreeNode*> q = { root };
        while (!q.empty()) {
            const int cnt = q.size();
            for (int _ = 0; _ < cnt; _++) {
                TreeNode* u = q.front();
                q.pop_front();
                
                if (!layer.count(u)) {
                    layer[u] = cur;
                }
                if (u->left) q.push_back(u->left);
                if (u->right) q.push_back(u->right);
            }
            cur++;
        }
        
        return dfs(root);
    }
private:
    unordered_map<TreeNode*, int> layer;
    TreeNode* dfs(TreeNode* root) {
        if (root == nullptr) return nullptr;
        
        if (root->left && layer[root->left] != layer[root] + 1) {
            return nullptr;
        } else {
            root->left = dfs(root->left);
        }
        
        if (root->right && layer[root->right] != layer[root] + 1) {
            return nullptr;
        } else {
            root->right = dfs(root->right);
        }
        return root;
    }
};
