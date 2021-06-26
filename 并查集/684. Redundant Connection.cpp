class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        init();
        for (auto& e : edges) {
            const int u = e[0], v = e[1];
            if (find_parent(u) == find_parent(v)) {
                return e;
            } else {
                merge(u, v);
            }
        }
        return {}; // never reach this branch
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