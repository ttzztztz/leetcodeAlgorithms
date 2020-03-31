/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> answer;
        vector<TreeNode*> allNode;
        deque<TreeNode*> q;
        q.push_back(root);
        while (!q.empty()) {
            TreeNode* top = q.front();
            q.pop_front();
            
            allNode.push_back(top);
            if (top->left) q.push_back(top->left);
            if (top->right) q.push_back(top->right);
        }
        
        const int N = allNode.size();
        vector<bool> visited(N, false);
        init(N);
        
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (isEqual(allNode[i], allNode[j])) {
                    visited[i] = visited[j] = true;
                    merge(i, j);
                }
            }
        }
        
        unordered_set<int> used;
        for (int i = 0; i < N; i++) {
            if (!visited[i]) continue;
            const int u = findParent(i);
            if (used.count(u)) continue;
            
            used.insert(u);
            answer.push_back(allNode[u]);
        }
        return answer;
    }
private:
    bool isEqual(TreeNode* $1, TreeNode* $2) {
        if ($1 == nullptr || $2 == nullptr) {
            return $1 == $2;
        }
        
        if ($1->val != $2->val) return false;
        return isEqual($1->left, $2->left) && isEqual($1->right, $2->right);
    }
    
    vector<int> parent;
    void init(int N) {
        parent = vector<int>(2 * N + 5);
        for (int i = 0; i <= 2 *N + 2; i++) parent[i] = i;
    }
    int findParent(int u) {
        if (parent[u] == u) return u;
        else return parent[u] = findParent(parent[u]);
    }
    void merge(int u, int v) {
        const int pU = findParent(u), pV = findParent(v);
        if (pU != pV) {
            parent[pU] = pV;
        }
    }
};
