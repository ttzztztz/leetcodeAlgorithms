class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        typedef long long ll;
        const int mod = 1e9+7;
        vector<vector<ll>> f(m + 1, vector<ll>(k + 2, 0));
        for (int i = 1; i <= m; i++) f[i][k] = 1;
        
        for (int i = n - 1; i >= 0; i--) {
            vector<vector<ll>> g(m + 1, vector<ll>(k + 2, 0));
            for (int j = 0; j <= m; j++) for (int x = 0; x <= k; x++) {
                
                for (int y = 1; y <= m; y++) {
                    g[j][x] = (g[j][x] + f[max(y, j)][y > j ? (x + 1) : x]) % mod;
                }
                
            }
            f = g;
        }
        
        return f[0][0];
    }
};