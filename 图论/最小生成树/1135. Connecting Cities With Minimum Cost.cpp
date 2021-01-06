class Solution {
public:
    int minimumCost(int N, vector<vector<int>>& connections) {
        int merged = 0, ans = 0;
        
        sort(connections.begin(), connections.end(), [](const auto& $1, const auto& $2) -> bool {
            return $1[2] < $2[2];
        });
        
        init(N);
        for (auto& connection : connections) {
            const int u = connection[0], v = connection[1], w = connection[2];
            
            if (find_parent(u) != find_parent(v)) {
                merged++;
                ans += w;
                merge(u, v);
            }
        }
        
        
        if (merged == N - 1) return ans;
        else return -1;
    }
private:
    vector<int> parent;
    void init(int n) {
        parent = vector<int>(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int find_parent(int u) {
        if (parent[u] == u) return u;
        else return parent[u] = find_parent(parent[u]);
    }
    void merge(int u, int v) {
        const int pu = find_parent(u), pv = find_parent(v);
        if (pu != pv) {
            parent[pu] = pv;
        }
    }
};
