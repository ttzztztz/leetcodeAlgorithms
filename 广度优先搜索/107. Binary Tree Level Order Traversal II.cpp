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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> answer;
        if (root == nullptr) {
            return answer;
        }

        deque<pair<TreeNode*, int>> queue;
        queue.emplace_back(root, 0);
        int lastLayer = -1;
        while (!queue.empty()) {
            pair<TreeNode*, int> item = queue.front();
            queue.pop_front();

            if (lastLayer != item.second) {
                lastLayer = item.second;
                answer.push_back(vector<int>());
            }

            answer[item.second].push_back(item.first->val);

            if (item.first->left != nullptr) {
                queue.emplace_back(item.first->left, item.second + 1);
            }
            if (item.first->right != nullptr) {
                queue.emplace_back(item.first->right, item.second + 1);
            }
        }

        std::reverse(answer.begin(), answer.end());
        return answer;
    }
};