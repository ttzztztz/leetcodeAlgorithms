/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 * Example of iterate a tree:
 * BSTIterator iterator = BSTIterator(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */


class BSTIterator {
public:
    /*
    * @param root: The root of binary tree.
    */BSTIterator(TreeNode * root) {
        // do intialization if necessary
        dfs(root);
    }

    /*
     * @return: True if there has next node, or false
     */
    bool hasNext() {
        return ptr != data.size();
    }

    /*
     * @return: return next node
     */
    TreeNode * next() {
        return data[ptr++];
    }
private:
    vector<TreeNode*> data;
    int ptr = 0;
    void dfs(TreeNode* u) {
        if (u == nullptr) return;
        dfs(u->left);
        data.push_back(u);
        dfs(u->right);
    }
};