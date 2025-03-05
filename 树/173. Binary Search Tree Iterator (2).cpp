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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        if (root != nullptr) stk.emplace_back(root, false);
    }
    
    int next() {
        while (!stk.empty() && stk.back().second == false) {
            auto [node, visited] = stk.back();
            stk.pop_back();

            if (node->right) stk.emplace_back(node->right, false);
            stk.emplace_back(node, true);
            if (node->left) stk.emplace_back(node->left, false);
        }
        
        auto [node, visited] = stk.back();
        stk.pop_back();
        return node->val;
    }
    
    bool hasNext() {
        return !stk.empty();
    }
private:
    vector<pair<TreeNode*, bool>> stk;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */