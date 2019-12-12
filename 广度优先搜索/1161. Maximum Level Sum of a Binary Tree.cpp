/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        vector<int> level{0};

        deque<pair<TreeNode*, int>> queue;
        queue.emplace_back(root, 1);
        while (!queue.empty()) {
            pair<TreeNode*, int> top = queue.front();
            queue.pop_front();

            if (top.second >= level.size()) {
                level.push_back(0);
            }
            level[top.second] += top.first->val;

            if (top.first->left) {
                queue.emplace_back(top.first->left, top.second + 1);
            }
            if (top.first->right) {
                queue.emplace_back(top.first->right, top.second + 1);
            }
        }

        int maxValue = -1;
        for (int i = 1; i < level.size(); i++) {
            maxValue = max(level[i], maxValue);
        }
        for (int i = 1; i < level.size(); i++) {
            if (level[i] == maxValue) {
                return i;
            }
        }
        return 0;
    }
};