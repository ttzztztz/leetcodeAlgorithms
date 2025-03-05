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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) return ans;

        deque<TreeNode*> q = {root};
        while (!q.empty()) {
            const int cnt = q.size();
            int num = numeric_limits<int>::min();

            for (int j = 0; j < cnt; j++) {
                TreeNode* cur = q.front();
                q.pop_front();

                num = max(num, cur->val);

                if (cur->left != nullptr) q.push_back(cur->left);
                if (cur->right != nullptr) q.push_back(cur->right);
            }
            ans.push_back(num);
        }
        return ans;
    }
};