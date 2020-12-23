class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        const int n = grid.size(), m = grid[0].size();
        vector<int> f(n, 0), g(m, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                f[i] = max(f[i], grid[i][j]);
                g[j] = max(g[j], grid[i][j]);
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans += min(f[i], g[j]) - grid[i][j];
            }
        }
        
        return ans;
    }
};
