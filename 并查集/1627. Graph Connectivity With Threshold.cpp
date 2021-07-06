class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        init();
        for (int j = threshold + 1; j <= n; j++) {
            for (int i = 1; i * j <= n; i++) {
                merge(j, i * j);
            }
        }
        
        const int q = queries.size();
        vector<bool> ans(q);
        for (int i = 0; i < q; i++) {
            const int x = queries[i][0], y = queries[i][1];
            
            if (threshold == 0) ans[i] = true;
            else ans[i] = (query(x) == query(y));
        }
        return ans;
    }
private:
    int parent[10001];
    void init() {
        for (int i = 0; i <= 10000; i++) parent[i] = i;
    }
    
    int query(int u) {
        if (u == parent[u]) return u;
        else return parent[u] = query(parent[u]);
    }
    
    void merge(int u, int v) {
        const int pu = query(u), pv = query(v);
        if (parent[pu] != pv) {
            parent[pu] = pv;
        }
    }
};