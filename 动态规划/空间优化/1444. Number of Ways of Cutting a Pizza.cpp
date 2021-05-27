class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        const int mod = 1e9+7;
        typedef long long ll;
        
        if (pizza.empty()) return 0;
        const int n = pizza.size(), m = pizza[0].size();
        vector<vector<ll>> f(n, vector<ll>(m, 0));
        
        int psum[51][51];
        memset(psum, 0, sizeof psum);
        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
            const int val = (pizza[i - 1][j - 1] == 'A') ? 1 : 0;
            psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + val;
        }
        
        auto sum = [&](int x, int y, int a, int b) -> int {
            x++, y++, a++, b++;
            return psum[a][b] - psum[x - 1][b] - psum[a][y - 1] + psum[x - 1][y - 1];
        };
        
        for (int i = 0; i <= k - 1; i++) {
            vector<vector<ll>> g(n, vector<ll>(m, 0));
            for (int x = 0; x < n; x++) for (int y = 0; y < m; y++) {
                ll& val = g[x][y];
                if (i == 0) {
                    val = (sum(x, y, n - 1, m - 1) > 0) ? 1 : 0;
                    continue;
                }

                for (int nx = x + 1; nx < n; nx++) {
                    if (sum(x, y, nx - 1, m - 1) > 0) {
                        val = (val + f[nx][y]) % mod;
                    }
                }

                for (int ny = y + 1; ny < m; ny++) {
                    if (sum(x, y, n - 1, ny - 1) > 0) {
                        val = (val + f[x][ny]) % mod;
                    }
                }
            }
            f = g;
        }
        
        return f[0][0];
    }
};