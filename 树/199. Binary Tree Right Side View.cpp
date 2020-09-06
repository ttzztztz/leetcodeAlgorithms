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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> answer;
        if (root == nullptr) return answer;
        
        deque<TreeNode*> q = {root};
        while (!q.empty()) {
            int last = -1;
            const int cnt = q.size();
            for (int _ = 0; _ < cnt; _++) {
                auto f = q.front();
                q.pop_front();
                
                last = f->val;
                if (f->left) q.push_back(f->left);
                if (f->right) q.push_back(f->right);
            }
            answer.push_back(last);
        }
        return answer;
    }
};
