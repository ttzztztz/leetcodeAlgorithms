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
    int deepestLeavesSum(TreeNode* root) {
        vector<int> sum(10005, 0);

        deque<pair<TreeNode*, int>> queue;
        queue.emplace_back(root, 0);
        int deepest = 0;
        while (!queue.empty()) {
            TreeNode* current;
            int layer;
            tie(current, layer) = queue.front();
            queue.pop_front();

            deepest = max(deepest, layer);
            sum[layer] += current->val;

            if (current->left) {
                queue.emplace_back(current->left, layer + 1);
            }
            if (current->right) {
                queue.emplace_back(current->right, layer + 1);
            }
        }

        return sum[deepest];
    }
};