class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        sort(A.begin(), A.end());
        
        const int n = A.size();
        typedef long long ll;
        const int kMod = 1e9+7;
        vector<ll> f(n, 0), g(n, 0);
        f[0] = 1;
        for (int i = 1; i < n; i++) f[i] = (f[i - 1] * 2) % kMod;
        g[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) g[i] = (g[i + 1] * 2) % kMod;
        
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            const ll delta = ((f[i] - g[i]) % kMod + kMod) % kMod;
            ans = (ans + delta * A[i] % kMod) % kMod;
        }
        return ans;
    }
};
