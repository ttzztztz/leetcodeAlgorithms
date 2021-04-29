class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        const int m = connections.size();
        if (n - 1 > m) return -1;
        int ans = 0;
        init(n);
        
        for (auto& connection : connections) {
            const int u = connection[0], v = connection[1];
            if (find_parent(u) != find_parent(v)) {
                ans++;
                merge(u, v);
            }
        }
        
        return n - 1 - ans;
    }
private:
    vector<int> parent;
    void init(int n) {
        parent = vector<int>(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find_parent(int u) {
        if (parent[u] == u) return u;
        else return parent[u] = find_parent(parent[u]);
    }
    void merge(int u, int v) {
        const int pu = find_parent(u), pv = find_parent(v);
        if (parent[pu] != pv) parent[pu] = pv;
    }
};