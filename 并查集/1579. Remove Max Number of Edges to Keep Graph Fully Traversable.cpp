class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        const int t = merge_edges(n, edges, -1);
        int ans = merge_edges(n, edges, 1) + merge_edges(n, edges, 2) - t;
        
        const int m = edges.size();
        if (size[find_parent(1)] != n) return -1;
        return m - ans;
    }
private:
    vector<int> parent, size;
    void init(int n) {
        parent = size = vector<int>(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    int find_parent(int u) {
        if (parent[u] == u) return u;
        else return parent[u] = find_parent(parent[u]);
    }
    
    void merge(int u, int v) {
        const int pu = find_parent(u), pv = find_parent(v);
        if (parent[pu] != pv) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
    
    int merge_edges(int n, vector<vector<int>>& edges, int type) {
        int ans = 0;
        init(n);
        for (auto& e : edges) {
            if (e[0] == 3) {
                const int u = e[1], v = e[2];
                if (find_parent(u) != find_parent(v)) {
                    merge(u, v);
                    ans++;
                }
            }
        }
        
        if (type != -1) {
            for (auto& e : edges) {
                if (e[0] == type) {
                    const int u = e[1], v = e[2];
                    if (find_parent(u) != find_parent(v)) {
                        merge(u, v);
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};