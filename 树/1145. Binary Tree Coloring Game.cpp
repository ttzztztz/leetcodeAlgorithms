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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        const int total = subtree_sum(root);
        auto [node, parent] = find_node(root, nullptr, x);
        
        const int l_size = subtree_sum(node->left);
        const int r_size = subtree_sum(node->right);
        const int node_size = l_size + r_size + 1;
        
        return (l_size > total - l_size) || (r_size > total - r_size) || (total - node_size > node_size);
    }
private:
    int subtree_sum(TreeNode* u) {
        if (u == nullptr) return 0;
        
        int ans = 1;
        ans += subtree_sum(u->left);
        ans += subtree_sum(u->right);
        return ans;
    }
    
    const pair<TreeNode*, TreeNode*> kNotFound = {nullptr, nullptr};
    pair<TreeNode*, TreeNode*> find_node(TreeNode* u, TreeNode* parent, int val) {
        if (u == nullptr) return kNotFound;
        
        if (u->val == val) return {u, parent};
        auto l_ans = find_node(u->left, u, val);
        if (l_ans != kNotFound) return l_ans;
        
        auto r_ans = find_node(u->right, u, val);
        if (r_ans != kNotFound) return r_ans;
        
        return kNotFound;
    }
};
