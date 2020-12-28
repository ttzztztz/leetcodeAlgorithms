class Solution {
public:
    int waysToDistribute(int n, int k) {
        const int mod = 1e9+7;
        typedef long long ll;
        
        vector<ll> f(k + 1, 0);
        f[k] = 1;
        for (int i = n - 1; i >= 0; i--) {
            vector<ll> g(k + 1, 0);
            for (int j = k; j >= 0; j--) {
                g[j] = (g[j] + j * f[j]) % mod;
                if (j + 1 <= k) g[j] = (g[j] + f[j + 1]) % mod;
            }
            f = g;
        }
        
        return f[0];
    }
};
