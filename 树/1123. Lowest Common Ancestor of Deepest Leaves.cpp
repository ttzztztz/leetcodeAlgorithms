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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (root == nullptr) return nullptr;
        
        dfs(root, 0);
        int minDeep = 99999;
        for (const auto& p: allLeaf) minDeep = min(minDeep, deep[p]);
        for (auto& p: allLeaf) {
            while (deep[p] > minDeep) p = parent[p];
        }
        
        while (!isEqual()) {
            for (auto& p : allLeaf) p = parent[p];
        }
        
        return allLeaf[0];
    }
private:
    vector<TreeNode*> allLeaf;
    int curDeep = 0;
    unordered_map<TreeNode*, TreeNode*> parent;
    unordered_map<TreeNode*, int> deep;
    void dfs(TreeNode* root, int d) {
        if (root == nullptr) return;
        
        deep[root] = d;
        bool isLeaf = true;
        if (root->left) {
            parent[root->left] = root;
            isLeaf = false;
            dfs(root->left, d + 1);
        }
        
        if (root->right) {
            parent[root->right] = root;
            isLeaf = false;
            dfs(root->right, d + 1);
        }
        
        if (isLeaf) {
            if (d > curDeep) {
                allLeaf = {root};
                curDeep = d;
            } else if (d == curDeep) {
                allLeaf.push_back(root);
            }
        }
    }
    bool isEqual() {
        for (int i = 1; i < allLeaf.size(); i++) {
            if (allLeaf[i] != allLeaf[0]) return false;
        }
        return true;
    }
};
