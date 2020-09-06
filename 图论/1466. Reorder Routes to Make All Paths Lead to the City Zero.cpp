class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        edges = vector<vector<PII>>(n + 1, vector<PII>{});
        for (const auto& con : connections) {
            edges[con[0]].emplace_back(con[1], 1);
            edges[con[1]].emplace_back(con[0], 0);
        }
        
        return dfs(0, -1);
    }
private:
    typedef pair<int, int> PII;
    vector<vector<PII>> edges;
    int dfs(int u, int parent) {
        int answer = 0;
        for (auto& p : edges[u]) {
            int v, cost;
            tie(v, cost) = p;
            
            if (v == parent) continue;
            answer += cost + dfs(v, u);
        }
        return answer;
    }
};
