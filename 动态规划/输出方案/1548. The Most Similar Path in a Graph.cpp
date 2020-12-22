class Solution {
public:
    vector<int> mostSimilar(int n, vector<vector<int>>& roads, vector<string>& names, vector<string>& targetPath) {
        edges_ = vector<vector<int>>(n, vector<int>{});
        for (auto& v : roads) {
            edges_[v[0]].push_back(v[1]);
            edges_[v[1]].push_back(v[0]);
        }
        
        unordered_map<string, int> map_name_to_idx;
        const int m = targetPath.size();
        
        for (int i = 0; i < names.size(); i++) map_name_to_idx[names[i]] = i;
        target_ = targetPath;
        names_ = names;
        
        f = vector<vector<int>>(m + 1, vector<int>(n + 1, m + 1));
        for (int i = 0; i < n; i++) f[0][i] = (target_[0] == names_[i]) ? 0 : 1;
        
        for (int i = 1; i < m; i++) {
            for (int u = 0; u < n; u++) {
                for (int v : edges_[u]) {
                    f[i][u] = min(f[i][u], f[i - 1][v] + (target_[i] == names_[u] ? 0 : 1));
                }
            }
        }
        
        int min_dist = numeric_limits<int>::max(), min_idx = -1;
        for (int i = 0; i < n; i++) {
            if (f[m - 1][i] < min_dist) {
                min_dist = f[m - 1][i];
                min_idx = i;
            }
        }
        
        Dfs(m - 1, min_idx);
        reverse(ans_.begin(), ans_.end());
        return ans_;
    }
private:
    vector<vector<int>> edges_;
    vector<string> target_, names_;
    vector<vector<int>> f;
    vector<int> ans_;
    
    bool Dfs(int idx, int node) {
        ans_.push_back(node);
        if (idx == 0) return true;
        
        for (int v : edges_[node]) {
            if (v == node) continue;

            if (f[idx - 1][v] + (target_[idx] == names_[node] ? 0 : 1) == f[idx][node]) {
                if (Dfs(idx - 1, v)) return true;
            }
        }
        
        ans_.pop_back();
        return false;
    }
};
