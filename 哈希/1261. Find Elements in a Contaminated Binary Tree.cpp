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
class FindElements {
public:
    FindElements(TreeNode* root) {
        if (root != nullptr) dfs(root, 0);
    }
    
    bool find(int target) {
        return val_set.count(target);
    }
private:
    unordered_set<int> val_set;

    void dfs(TreeNode* root, int idx) {
        val_set.insert(idx);

        if (root->left) dfs(root->left, 2 * idx + 1);
        if (root->right) dfs(root->right, 2 * idx + 2);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */