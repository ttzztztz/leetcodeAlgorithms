class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        edges = vector<vector<PII>>(n + 1);
        for (auto& connection : connections) {
            edges[connection[0]].emplace_back(connection[1], 1);
            edges[connection[1]].emplace_back(connection[0], 0);
        }
        
        return dfs(0, -1);
    }
private:
    typedef pair<int, int> PII;
    vector<vector<PII>> edges;
    
    int dfs(int u, int parent) {
        int ans = 0;
        for (auto& [v, w] : edges[u]) {
            if (v == parent) continue;
            ans += w + dfs(v, u);
        }
        return ans;
    }
};