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
        vector<int> answer;
        if (root == nullptr) return answer;
        
        deque<TreeNode*> q = {root};
        while (!q.empty()) {
            const int cnt = q.size();
            int mx = numeric_limits<int>::min();
            for (int _ = 0; _ < cnt; _++) {
                const auto f = q.front();
                q.pop_front();
                
                mx = max(mx, f->val);
                if (f->left) q.push_back(f->left);
                if (f->right) q.push_back(f->right);
            }
            answer.push_back(mx);
        }
        
        return answer;
    }
};