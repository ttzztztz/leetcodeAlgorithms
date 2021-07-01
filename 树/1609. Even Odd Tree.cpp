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

        int layer = 0;
        deque<TreeNode*> q = {root};
        while (!q.empty()) {
            const int cnt = q.size();
            int last = -1;

            for (int idx = 0; idx < cnt; idx++) {
                auto u = q.front();
                q.pop_front();
                
                const int val = u->val;
                if (layer % 2 == 0) {
                    if (val % 2 == 0 || (idx >= 1 && last >= val)) return false;
                } else { // layer % 2 == 1
                    if (val % 2 == 1 || (idx >= 1 && last <= val)) return false;
                }
                last = val;
                
                if (u->left) q.push_back(u->left);
                if (u->right) q.push_back(u->right);
            }

            layer++;
        }
        return true;
    }
};