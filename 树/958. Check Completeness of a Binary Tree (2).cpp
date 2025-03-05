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
    bool isCompleteTree(TreeNode* root) {
        if (root == nullptr) return true;

        bool find_null = false;
        deque<TreeNode*> q = { root };
        while (!q.empty()) {
            auto node = q.front();
            q.pop_front();

            if (node == nullptr) {
                find_null = true;
                continue;
            } else { // node != nullptr
                if (find_null) return false;
            }

            q.push_back(node->left);
            q.push_back(node->right);
        }

        return true;
    }
};