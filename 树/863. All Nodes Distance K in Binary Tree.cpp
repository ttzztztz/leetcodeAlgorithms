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
    vector<int> distanceK(TreeNode * root, TreeNode * target, int K) {
        dfs(root, nullptr);
        
        vector<int> ans;
        deque<TreeNode*> q = {target};
        unordered_set<TreeNode*> visited;
        int layer = 0;
        while (!q.empty()) {
            if (layer > K) break;
            const int cnt = q.size();
            for (int _ = 0; _ < cnt; _++) {
                TreeNode* u = q.front();
                if (layer == K) {
                    ans.push_back(u->val);
                }
                q.pop_front();
                visited.insert(u);
                
                if (parent[u] && !visited.count(parent[u])) q.push_back(parent[u]), visited.insert(parent[u]);
                if (u->left && !visited.count(u->left)) q.push_back(u->left), visited.insert(u->left);
                if (u->right && !visited.count(u->right)) q.push_back(u->right), visited.insert(u->right);
            }
            layer++;
        }
        
        return ans;
    }
private:
    unordered_map<TreeNode*, TreeNode*> parent;
    void dfs(TreeNode* u, TreeNode* par) {
        if (u == nullptr) return;
        
        parent[u] = par;
        dfs(u->left, u);
        dfs(u->right, u);
    }
};