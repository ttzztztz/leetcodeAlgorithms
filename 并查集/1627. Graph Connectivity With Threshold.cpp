class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        init(n);
        for (int i = threshold + 1; i <= n; i++) {
            for (int j = 1; j * i <= n; j++) {
                merge(i * j, i);
            }
        }
        
        vector<bool> ans;
        for (int i = 0; i < queries.size(); i++) {
            const int pu = fp(queries[i][0]), pv = fp(queries[i][1]);
            ans.push_back(pu == pv);
        }
        return ans;
    }
private:
    int parent[10005];
    void init(int n) {
        for (int i = 0; i <= n; i++) parent[i] = i;
    }
    void merge(int u, int v) {
        const int pu = fp(u), pv = fp(v);
        if (pu != pv) {
            parent[pu] = pv;
        }
    }
    int fp(int u) {
        if (parent[u] != u) return parent[u] = fp(parent[u]);
        else return parent[u];
    }
};
