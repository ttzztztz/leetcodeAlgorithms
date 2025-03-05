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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (root == nullptr || target == nullptr) return {};

        unordered_map<TreeNode*, TreeNode*> parent;
        dfs_parent(parent, root);
        return bfs_k_dist_nodes(parent, target, k);
    }
private:
    void dfs_parent(unordered_map<TreeNode*, TreeNode*>& parent, TreeNode* root) {
        if (root == nullptr) return;

        if (root->left != nullptr) {
            parent[root->left] = root;
            dfs_parent(parent, root->left);
        }

        if (root->right != nullptr) {
            parent[root->right] = root;
            dfs_parent(parent, root->right);
        }
    }

    vector<int> bfs_k_dist_nodes(unordered_map<TreeNode*, TreeNode*>& parent, TreeNode* target, int k) {
        vector<int> ans;
        int len = 0;
        deque<TreeNode*> q = {target};
        unordered_set<TreeNode*> visited;
        visited.insert(target);

        while (!q.empty()) {
            const int cnt = q.size();

            for (int i = 0; i < cnt; i++) {
                TreeNode* cur = q.front();
                q.pop_front();

                if (len == k) {
                    ans.push_back(cur->val);
                }

                if (cur->left && !visited.count(cur->left)) {
                    q.push_back(cur->left);
                    visited.insert(cur->left);
                }
                if (cur->right && !visited.count(cur->right)) {
                    q.push_back(cur->right);
                    visited.insert(cur->right);
                }

                if (parent.count(cur) && !visited.count(parent[cur])) {
                    q.push_back(parent[cur]);
                    visited.insert(parent[cur]);
                }
            }

            if (len == k) {
                break;
            }
            len++;
        }

        return ans;
    }
};