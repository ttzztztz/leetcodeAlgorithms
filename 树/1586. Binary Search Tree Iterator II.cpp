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
        dfs(root);
    }
    
    bool hasNext() {
        const int n = data.size();
        return ptr + 1 < n;
    }
    
    int next() {
        return data[++ptr];
    }
    
    bool hasPrev() {
        return ptr - 1 >= 0;
    }
    
    int prev() {
        return data[--ptr];
    }
private:
    vector<int> data;
    int ptr = -1;
    
    void dfs(TreeNode* u) {
        if (u == nullptr) return;

        dfs(u->left);
        data.push_back(u->val);
        dfs(u->right);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * bool param_1 = obj->hasNext();
 * int param_2 = obj->next();
 * bool param_3 = obj->hasPrev();
 * int param_4 = obj->prev();
 */
