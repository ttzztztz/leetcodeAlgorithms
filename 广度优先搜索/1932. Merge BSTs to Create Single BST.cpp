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
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_map<int, TreeNode*> val_root;
        unordered_map<int, int> cnt;
        for (auto& tree : trees) {
            cnt_nodes(tree, cnt);
            val_root[tree->val] = tree;
        }
        
        TreeNode* root = nullptr;
        for (auto& tree : trees) {
            if (cnt[tree->val] == 1) {
                root = tree;
                break;
            }
        }
        if (root == nullptr) return nullptr;
        
        deque<TreeNode*> q = { root };
        while (!val_root.empty() && !q.empty()) {
            auto u = q.front();
            q.pop_front();
            
            if (!val_root.count(u->val)) continue;
            auto v = val_root[u->val];
            
            u->left = v->left;
            u->right = v->right;
            val_root.erase(u->val);
            
            vector<TreeNode*> leaves;
            get_leaf(u, leaves);
            for (auto& leaf : leaves) q.push_back(leaf);
        }
        
        if (is_valid(root, -inf, inf) && val_root.empty()) return root;
        else return nullptr;
    }
private:
    const int inf = numeric_limits<int>::max() / 2;
    bool is_valid(TreeNode* u, int l, int r) {
        if (u == nullptr) return true;
        if (l > r || !(l <= u->val && u->val <= r)) return false;
        
        return is_valid(u->left, l, u->val - 1) && is_valid(u->right, u->val + 1, r);
    }
    
    void cnt_nodes(TreeNode* u, unordered_map<int, int>& cnt) {
        if (u == nullptr) return;
        cnt[u->val]++;
        
        cnt_nodes(u->left, cnt);
        cnt_nodes(u->right, cnt);
    }
    
    void get_leaf(TreeNode* u, vector<TreeNode*>& ans, bool is_root = true) {
        if (u == nullptr) return;
        
        if (!is_root && u->left == nullptr && u->right == nullptr) {
            ans.push_back(u);
        }
        
        get_leaf(u->left, ans, false);
        get_leaf(u->right, ans, false);
    }
};