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
    int widthOfBinaryTree(TreeNode* root) {
        long long answer = 0;
        if (root == nullptr) return answer;
        
        deque<pair<TreeNode*, long long>> q = {{root, 0}};
        int layer = 0;
        while (!q.empty()) {
            const int cnt = q.size();
            long long start = numeric_limits<long long>::max();
            for (int _ = 0; _ < cnt; _++) {
                TreeNode* u;
                long long id;
                tie(u, id) = q.front();
                q.pop_front();
                start = min(start, id);
                answer = max(answer, id - start + 1);
                
                if (u->left) q.emplace_back(u->left, ((id << 1) + 1) % INT_MAX);
                if (u->right) q.emplace_back(u->right, ((id << 1) + 2) % INT_MAX);
            }
            layer++;
        }
        
        return answer;
    }
};