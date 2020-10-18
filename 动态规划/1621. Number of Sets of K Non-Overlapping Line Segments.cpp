class Solution {
public:
    int numberOfSets(int n, int k) {
        memset(f, 0xff, sizeof f);
        
        this->N = n - 1;
        return dfs(0, k, 0);
    }
private:
    typedef long long ll;
    ll f[1005][1005][2];
    int N;
    const int mod = 1e9+7;
    
    ll dfs(int n, int k, int s) {
        if (n == N) {
            if (k == 0) return 1;
            else return 0;
        }
        if (k < 0) return 0;
        
        ll& val = f[n][k][s];
        if (val != -1) return val;
        
        ll ans = 0;
        if (s == 0) { // not placed
            ans = (ans + dfs(n + 1, k, 0)) % mod;
            ans = (ans + dfs(n + 1, k - 1, 1)) % mod;
        } else { // placed
            ans = (ans + dfs(n + 1, k, 1)) % mod;
            ans = (ans + dfs(n, k, 0)) % mod;
        }
        return val = ans;
    }
};
