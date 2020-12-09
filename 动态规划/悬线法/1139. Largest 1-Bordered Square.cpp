class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        const int n = grid.size(), m = grid[0].size();
        vector<vector<int>> f(n + 2, vector<int>(m + 2, 0)), g(n + 2, vector<int>(m + 2, 0));
        
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = m; j >= 1; j--) {
                const int t = grid[i - 1][j - 1];
                if (t != 1) continue;
                
                f[i][j] = f[i][j + 1] + 1;
            }
        }
        
        for (int i = n; i >= 1; i--) {
            for (int j = 1; j <= m; j++) {
                const int t = grid[i - 1][j - 1];
                if (t != 1) continue;
                
                g[i][j] = g[i + 1][j] + 1;
            }
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (grid[i - 1][j - 1] != 1) continue;

                const int e = min(f[i][j], g[i][j]);
                // (i, j), (i + e, j), (i, j + e), (i + e, j + e)
                for (int k = 0; k <= e; k++) {
                    if (f[i + k][j] >= k + 1 && g[i][j + k] >= k + 1) {
                        ans = max(ans, (k + 1) * (k + 1));
                    }
                }
            }
        }
        return ans;
    }
};
