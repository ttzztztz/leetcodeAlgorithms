class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        this->n = n;
        e = vector<vector<PII>>(n + 1);
        for (auto& ed : edges) {
            e[ed[0]].emplace_back(ed[1], ed[2]);
            e[ed[1]].emplace_back(ed[0], ed[2]);
        }
        d = vector<ll>(n + 1, numeric_limits<int>::max());
        calc_d();
        f = vector<ll>(n + 1, -1);
        return dfs(1);
    }
private:
    typedef long long ll;
    typedef pair<int, int> PII;
    const int mod = 1e9+7;
    
    vector<vector<PII>> e;
    vector<ll> d;
    vector<ll> f;
    int n;
    
    void calc_d() {
        d[n] = 0;
        priority_queue<PII, vector<PII>, greater<>> heap;
        heap.emplace(0, n);
        
        while (!heap.empty()) {
            auto [w, u] = heap.top();
            heap.pop();
            d[u] = min(d[u], 1ll * w);
            
            for (auto& [v, nw] : e[u]) {
                if (d[v] > d[u] + nw) {
                    d[v] = d[u] + nw;
                    heap.emplace(d[v], v);
                }
            }
        }
    }
    
    ll dfs(int u) {
        if (u == n) return 1;
        ll& val = f[u];
        if (val != -1) return val;
        
        ll ans = 0;
        for (auto& [v, w] : e[u]) {
            if (d[v] < d[u]) ans = (ans + dfs(v)) % mod;
        }
        return val = ans;
    }
};
