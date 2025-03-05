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
    bool isEvenOddTree(TreeNode* root) {
        if (root == nullptr) return true;

        deque<TreeNode*> q = { root };
        int layer = 0;
        while (!q.empty()) {
            const int cnt = q.size();

            int last = -1;
            for (int i = 0; i < cnt; i++) {
                TreeNode* u = q.front();
                q.pop_front();

                if ((u->val % 2) == (layer % 2)) return false;
                if (i > 0 && layer % 2 == 0 && last >= u->val) return false;
                if (i > 0 && layer % 2 == 1 && last <= u->val) return false;
                last = u->val;

                if (u->left != nullptr) q.push_back(u->left);
                if (u->right != nullptr) q.push_back(u->right);
            }
            layer++;
        }

        return true;
    }
};