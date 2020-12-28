class Solution {
public:
    int waysToDistribute(int n, int k) {
        memset(f, 0xff, sizeof f);
        this->n = n, this->k = k;
        
        return dfs(1, 1);
    }
private:
    const int mod = 1e9+7;
    typedef long long ll;
    ll f[1005][1005];
    int n, k;
    
    ll dfs(int i, int j) {
        if (i == n) return (j == k) ? 1 : 0;
        ll& val = f[i][j];
        if (val != -1) return val;
        
        ll ans = 0;
        ans = (ans + j * dfs(i + 1, j)) % mod;
        if (j + 1 <= k) ans = (ans + dfs(i + 1, j + 1)) % mod;
        return val = ans;
    }
};
