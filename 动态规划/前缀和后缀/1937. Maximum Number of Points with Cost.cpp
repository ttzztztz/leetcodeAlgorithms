class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        typedef long long ll;
        const int n = points.size(), m = points[0].size();
        
        vector<vector<ll>> f(n + 1, vector<ll>(m + 1)), g(n + 1, vector<ll>(m + 1)), h(n + 1, vector<ll>(m + 1));
        for (int i = n; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                
                if (i == n) f[i][j] = 0;
                else f[i][j] = max(f[i][j], max(g[i + 1][j] - j, h[i + 1][j] + j));
                
            }
            
            for (int j = 0; j < m; j++) {
                if (j == 0) g[i][j] = f[i][j] + j + (i == 0 ? 0 : points[i - 1][j]);
                else g[i][j] = max(g[i][j - 1], f[i][j] + j + (i == 0 ? 0 : points[i - 1][j]));
            }
            
            for (int j = m - 1; j >= 0; j--) {
                if (j == m - 1) h[i][j] = f[i][j] - j + (i == 0 ? 0 : points[i - 1][j]);
                else h[i][j] = max(h[i][j + 1], f[i][j] - j + (i == 0 ? 0 : points[i - 1][j]));
            }
        }

        ll ans = 0;
        for (int i = 0; i < m; i++) ans = max(ans, f[0][i]);
        return ans;
    }
};