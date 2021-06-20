class Solution {
public:
    int kInversePairs(int n, int k) {
        typedef long long ll;
        const int mod = 1e9+7;
        
        vector<ll> f(k + 1, 0), pref(k + 1, 0);
        auto sum = [&](int j1, int j2) -> ll {
            return (pref[min(k, j2)] -
                (j1 >= 1 ? pref[j1 - 1] : 0) + mod) % mod;
        };
        
        f[k] = 1;
        for (int j = 0; j <= k; j++) {
            pref[j] = (j >= 1 ? pref[j - 1] : 0) + f[j];
        }
        
        for (int i = n; i >= 1; i--) {
            vector<ll> nf(k + 1, 0), npref(k + 1, 0);
            for (int j = 0; j <= k; j++) {
                nf[j] = sum(j, j + i - 1);

                npref[j] = (
                    (j >= 1 ? npref[j - 1] : 0) + nf[j]
                ) % mod;
            }
            f = nf, pref = npref;
        }
        return f[0];
    }
};