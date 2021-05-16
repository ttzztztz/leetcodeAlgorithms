class Solution {
public:
    int rearrangeSticks(int n, int k) {
        this->n = n;
        memset(f, 0xff, sizeof f);
        return dfs(n, k);
    }
private:
    typedef long long ll;
    const int mod = 1e9+7;
    ll f[1005][1005];
    int n;
    
    ll dfs(int len, int k) {
        if (len == 0) return (k == 0);
        if (k < 0) return 0;
        
        ll& val = f[len][k];
        if (val != -1) return val;
        ll ans = 0;
        ans = (ans + dfs(len - 1, k - 1)) % mod;
        ans = (ans + (n - len) * dfs(len - 1, k)) % mod;
        return val = ans;
    }
};