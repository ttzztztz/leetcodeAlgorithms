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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> f;
        typedef tuple<TreeNode*, int, int> State;
        deque<State> q = {{root, 0, 0}};
        while (!q.empty()) {
            TreeNode* u;
            int x, y;
            tie(u, x, y) = q.front();
            q.pop_front();
            
            f[x][y].insert(u->val);
            if (u->left) q.emplace_back(u->left, x - 1, y + 1);
            if (u->right) q.emplace_back(u->right, x + 1, y + 1);
        }
        
        vector<vector<int>> answer;
        for (auto& p : f) {
            const auto& pts = p.second;
            vector<int> tmp;
            for (auto& t : pts) {
                for (int i : t.second) tmp.push_back(i);
            }
            answer.push_back(tmp);
        }
        return answer;
    }
};