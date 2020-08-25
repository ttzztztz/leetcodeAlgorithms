class Solution {
public:
    /**
     * @param n: maximum index of position.
     * @param m: the number of undirected edges.
     * @param x: 
     * @param y: 
     * @param w: 
     * @return: return the minimum risk value.
     */
    int getMinRiskValue(int n, int m, vector<int> &x, vector<int> &y, vector<int> &w) {
        init();
        typedef tuple<int, int, int> TII;
        vector<TII> v;
        for (int i = 0; i < m; i++) {
            v.emplace_back(x[i], y[i], w[i]);
        }
        sort(v.begin(), v.end(), [](const auto& $1, const auto& $2) -> bool {
            return get<2>($1) < get<2>($2);
        });
        
        for (int i = 0; i < m; i++) {
            int a, b, we;
            tie(a, b, we) = v[i];
            
            merge(a, b);
            if (findParent(0) == findParent(n)) return we;
        }
        return -1;
    }
private:
    int parent[55];
    void init() {
        for (int i = 0; i <= 50; i++) parent[i] = i;
    }
    int findParent(int u) {
        if (u == parent[u]) return u;
        return parent[u] = findParent(parent[u]);
    }
    void merge(int u, int v) {
        int pu = findParent(u), pv = findParent(v);
        parent[pu] = pv;
    }
};
