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
    map<TreeNode*, TreeNode*> parent;
    TreeNode* dfs1(TreeNode* u, TreeNode* target) {
        if (u == nullptr) {
            return nullptr;
        }
        if (u == target) {
            return target;
        }

        TreeNode* answer = dfs1(u->left, target);
        if (answer != nullptr) {
            return answer;
        }

        answer = dfs1(u->right, target);
        if (answer != nullptr) {
            return answer;
        }

        return nullptr;
    }
    void dfs2(TreeNode* u) {
        if (u->left) {
            parent[u->left] = u;
            dfs2(u->left);
        }
        if (u->right) {
            parent[u->right] = u;
            dfs2(u->right);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        TreeNode* u = dfs1(root, target);
        dfs2(root);

        vector<int> answer;
        set<TreeNode*> visited;

        deque<pair<TreeNode*, int>> queue;
        visited.insert(u);
        queue.emplace_back(u, 0);

        while (!queue.empty()) {
            TreeNode* node;
            int dist;
            tie(node, dist) = queue.front();
            queue.pop_front();

            if (dist == k) {
                answer.push_back(node->val);
            }

            if (parent.count(node) && parent[node] && !visited.count(parent[node])) {
                queue.emplace_back(parent[node], dist + 1);
                visited.insert(parent[node]);
            }
            if (node->left && !visited.count(node->left)) {
                queue.emplace_back(node->left, dist + 1);
                visited.insert(node->left);
            }
            if (node->right && !visited.count(node->right)) {
                queue.emplace_back(node->right, dist + 1);
                visited.insert(node->right);
            }
        }

        return answer;
    }
};