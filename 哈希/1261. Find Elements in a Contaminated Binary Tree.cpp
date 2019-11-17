/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
public:
    unordered_set<int> exist;
    void build(TreeNode* root, int val) {
        if (root == nullptr) {
            return;
        }

        exist.insert(val);
        root->val = val;

        build(root->left, 2 * val + 1);
        build(root->right, 2 * val + 2);
    }
    FindElements(TreeNode* root) {
        root->val = 0;
        exist.insert(0);
        build(root->left, 1);
        build(root->right, 2);
    }

    bool find(int target) {
        return exist.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */