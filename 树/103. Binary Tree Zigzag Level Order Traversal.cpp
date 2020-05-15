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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        
        if (root == nullptr) return answer;
        deque<TreeNode*> q;
        q.push_back(root);
        int layer = 0;
        while (!q.empty()) {
            answer.push_back(vector<int>{});
            const int cnt = q.size();
            for (int _ = 0; _ < cnt; _++) {
                TreeNode* u = q.front();
                answer[layer].push_back(u->val);
                q.pop_front();
                
                if (u->left) q.push_back(u->left);
                if (u->right) q.push_back(u->right);
            }
            layer++;
        }
        
        for (int i = 0; i < answer.size(); i++) {
            if (i % 2 == 1) {
                reverse(answer[i].begin(), answer[i].end());
            }
        }
        return answer;
    }
};
