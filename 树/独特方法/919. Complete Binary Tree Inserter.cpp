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
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        this->root = root;
        this->q = {root};
    }
    
    int insert(int v) {
        auto [val, root] = traverse();
        *val = new TreeNode(v);
        return root->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
private:
    TreeNode* root;
    deque<TreeNode*> q;
    pair<TreeNode**, TreeNode*> traverse() {
        while (!q.empty()) {
            TreeNode* u = q.front();
            if (u->left == nullptr) {
                return {&(u->left), u};
            }
            if (u->right == nullptr) {
                return {&(u->right), u};
            }
            q.pop_front();
            
            if (u->left) q.push_back(u->left);
            if (u->right) q.push_back(u->right);
        }
        
        return {nullptr, nullptr}; // never reach this branch
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
