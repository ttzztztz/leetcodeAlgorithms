class Solution {
public:
    int uniquePaths(int m, int n) {
        // C(n+m,n)
        // C(x)(y)=C(x-1)(y-1)+C(x-1)(y)
        
        // f[x][y] = f[x-1][y] + f[x][y-1] => f[n][m]
        typedef long long ll;
        // ll f[m+2][n+2];
        // memset(f, 0, sizeof f);
        // for (int i = m; i >= 1; i--) {
        //     for (int j = n; j >= 1; j--) {
        //         if (i == m && j == n) f[i][j] = 1;
        //         else f[i][j] = f[i][j + 1] + f[i + 1][j];
        //     }
        // }
        vector<ll> f(n + 2, 0);
        for (int i = m; i >= 1; i--) {
            vector<ll> g(n + 2, 0);
            for (int j = n; j >= 1; j--) {
                if (i == m && j == n) g[j] = 1;
                else g[j] = g[j + 1] + f[j];
            }
            f = g;
        }
        return f[1];
    }
};