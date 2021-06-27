class Solution {
public:
    int waysToBuildRooms(vector<int>& prevRoom) {
        memset(cnt, 0, sizeof cnt);
        memset(frac, 0, sizeof frac);
        this->n = prevRoom.size();
        edges = vector<vector<int>>(n);
        
        for (int i = 1; i < n; i++) {
            edges[prevRoom[i]].push_back(i);
        }
        
        frac[0] = 1;
        for (int i = 1; i <= 200000; i++) {
            frac[i] = (1ll * frac[i - 1] * i) % mod;
        }
        
        // cout << endl;
        dfs1(0);
        return dfs(0);
    }
private:
    typedef long long ll;
    const int mod = 1e9+7;
    int n;
    
    ll cnt[100005], frac[200005];
    
    ll fast_pow(ll a, ll b) {
        ll ans = 1, base = a;
        while (b) {
            if (b & 1) {
                ans = (ans * base) % mod;
            }
            base = (base * base) % mod;
            b >>= 1;
        }
        return ans;
    }
    
    ll inv(ll a) {
        return fast_pow(a, mod - 2);
    }
    
    ll C(ll a, ll b) {
        ll ans = (frac[a] * inv(frac[b])) % mod;
        ans = (ans * inv(frac[a - b])) % mod;
        // cout << "C" << a << "," << b << "=" << ans << endl;
        return ans;
    }
    
    vector<vector<int>> edges;
    int dfs1(int u) {
        int cur = 1;
        for (int v : edges[u]) {
            cur += dfs1(v);
        }
        return cnt[u] = cur;
    }
    
    ll dfs(int u) {
        ll ans = 1;
        for (int v : edges[u]) {
            ans = (ans * dfs(v)) % mod;
        }
        int t = cnt[u] - 1;
        for (int v : edges[u]) {
            ans = (ans * C(t, cnt[v])) % mod;
            t -= cnt[v];
        }
        return ans;
    }
};