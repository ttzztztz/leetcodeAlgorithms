class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        init();
        vector<tuple<int, int, int>> edges;
        const int n = points.size();
        for (int i = 0; i < n; i++) for (int j = 0; j < i; j++) {
            edges.emplace_back(i, j, abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]));
        }
        
        sort(edges.begin(), edges.end(), [&](const auto& lhs, const auto& rhs) -> bool {
            return get<2>(lhs) < get<2>(rhs);
        });
        
        const int m = edges.size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            auto& [u, v, w] = edges[i];
            if (find_parent(u) != find_parent(v)) {
                ans += w;
                merge(u, v);
            }
        }
        return ans;
    }
private:
    int parent[1005];
    
    void init() {
        for (int i = 0; i <= 1000; i++) parent[i] = i;
    }
    
    int find_parent(int u) {
        if (u == parent[u]) return u;
        else return parent[u] = find_parent(parent[u]);
    }
    
    void merge(int u, int v) {
        const int pu = find_parent(u), pv = find_parent(v);
        if (pu != pv) {
            parent[pu] = pv;
        }
    }
};