const int mod = 1e9+7;
typedef long long ll;

ll f[10001][101];

class Solution {
public:
    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        const int q = queries.size();
        vector<int> ans(q, 0);
        memset(f, 0xff, sizeof f);
        
        vector<ll> frac(10001, 1);
        for (ll i = 2; i <= 10000; i++) {
            frac[i] = (frac[i - 1] * i) % mod;
        }
        
        auto fast_pow = [](int a, int b) -> ll {
            ll ans = 1, base = a;
            while (b) {
                if (b % 2) {
                    ans = (ans * base) % mod;
                }
                base = (base * base) % mod;
                b >>= 1;
            }
            return ans;
        };
        
        auto inverse = [&](int a) -> ll {
            return fast_pow(a, mod - 2);
        };
        
        auto C = [&](int n, int m) -> ll {
            ll ans = (frac[n] * inverse(frac[m])) % mod;
            return (ans * inverse(frac[n - m])) % mod;
        };
        
        for (int i = 0; i < q; i++) {
            const int n = queries[i][0], k = queries[i][1];
            const int l = log2(k);
            
            if (k == 1) {
                ans[i] = 1;
            } else {
                ll val = n;
                for (int j = 2; j <= min(l, n); j++) {
                    val = (val + (dfs(k, j) * C(n, n - j))) % mod;
                }
                ans[i] = val;
            }
        }
        return ans;
    }
private:
    ll dfs(int k, int n) {
        if (n == 1) return 1;
        ll& val = f[k][n];
        if (val != -1) return val;
        
        ll ans = 0;
        for (int x = 2; x <= sqrt(k); x++) {
            if (k % x == 0) {
                if (x * x == k) {
                    ans = (ans + dfs(k / x, n - 1)) % mod;
                } else {
                    ans = (ans + dfs(k / x, n - 1) + dfs(x, n - 1)) % mod;
                }
            }
        }
        return val = ans;
    }
};
