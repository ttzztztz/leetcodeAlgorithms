class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        this->n = n;
        for (int i = 0; i < edges.size(); i++) {
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), [&](auto& lhs, auto& rhs) -> bool {
            return lhs[2] < rhs[2];
        });
        
        const int original = MST(edges, -1, -1);
        vector<int> critical, pseudo;
        for (auto& edge : edges) {
            const int idx = edge[3];
            if (MST(edges, -1, idx) > original) critical.push_back(idx);
            else if (MST(edges, idx, -1) == original) pseudo.push_back(idx);
        }        
        return { critical, pseudo };
    }
private:
    int parent[101], n;
    void init() {
        for (int i = 0; i <= 100; i++) {
            parent[i] = i;
        }
    }
    int find_parent(int u) {
        if (u == parent[u]) return u;
        else return parent[u] = find_parent(parent[u]);
    }
    void merge(int u, int v) {
        const int pu = find_parent(u), pv = find_parent(v);
        if (parent[pu] != pv) {
            parent[pu] = pv;
        }
    }
    int MST(const vector<vector<int>>& edges, int force_insert, int force_delete) {
        init();
        
        int cnt = 0, ans = 0;
        for (const auto& edge : edges) {
            const int u = edge[0], v = edge[1], w = edge[2], idx = edge[3];
            if (idx == force_insert) {
                merge(u, v);
                cnt++;
                ans += w;
            }
        }
        
        for (const auto& edge : edges) {
            const int u = edge[0], v = edge[1], w = edge[2], idx = edge[3];
            if (idx == force_delete) continue;
            
            if (find_parent(u) != find_parent(v)) {
                merge(u, v);
                ans += w;
                cnt++;
            }
        }
        
        if (cnt != n - 1) return numeric_limits<int>::max();
        else return ans;
    }
};