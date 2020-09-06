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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        // delete
        for (const auto& v : to_delete) delVal.insert(v);
        TreeNode* newRoot = dfs1(root);
        // dfs
        
        for (const auto& p : all) {
            if (!visited.count(p)) {
                answer.push_back(p);
                dfs2(p);
            }
        }
        return answer;
    }
private:
    vector<TreeNode*> all;
    unordered_set<int> delVal;
    vector<TreeNode*> answer;
    unordered_set<TreeNode*> visited;
    TreeNode* dfs1(TreeNode* u) {
        if (u == nullptr) return nullptr;
        
        if (!delVal.count(u->val)) {
            all.push_back(u);
        }
        u->left = dfs1(u->left);
        u->right = dfs1(u->right);
        if (delVal.count(u->val)) {
            return nullptr;
        } else {
            return u;
        }
    }
    void dfs2(TreeNode* u) {
        if (u == nullptr) return;
        
        visited.insert(u);
        if (u->left) dfs2(u->left);
        if (u->right) dfs2(u->right);
    }
};
