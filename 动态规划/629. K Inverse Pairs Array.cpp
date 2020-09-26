class Solution {
public:
    int kInversePairs(int n, int k) {
        memset(f, 0, sizeof f);
        memset(g, 0, sizeof g);
        for (int i = 0; i <= n; i++) f[i][0] = g[i][0] = 1;
        for (int i = 1; i <= k; i++) g[0][i] = 1;
        
        const int mod = 1e9+7;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                f[i][j] = (f[i][j] + g[i - 1][j]) % mod;
                if (i <= j) f[i][j] = (f[i][j] - g[i - 1][j - i] + mod) % mod;
                
                g[i][j] = (g[i][j - 1] + f[i][j]) % mod;
            }
        }
        
        return f[n][k];
    }
private:
    int f[1005][1005], g[1005][1005];
};
