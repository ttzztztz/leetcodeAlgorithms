class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        const int n = grid.size(), m = grid[0].size();
        vector<vector<int>> l(n + 2, vector<int>(m + 2, 0));
        vector<vector<int>> r(n + 2, vector<int>(m + 2, 0));
        vector<vector<int>> u(n + 2, vector<int>(m + 2, 0));
        vector<vector<int>> d(n + 2, vector<int>(m + 2, 0));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (grid[i - 1][j - 1] == 'E') {
                    l[i][j] = l[i][j - 1] + 1;
                    u[i][j] = u[i - 1][j] + 1;
                } else if (grid[i - 1][j - 1] == '0') {
                    l[i][j] = l[i][j - 1];
                    u[i][j] = u[i - 1][j];
                }
            }
            
            for (int j = m; j >= 1; j--) {
                if (grid[i - 1][j - 1] == 'E') {
                    r[i][j] = r[i][j + 1] + 1;
                } else if (grid[i - 1][j - 1] == '0') {
                    r[i][j] = r[i][j + 1];
                }
            }
        }
        
        for (int i = n; i >= 1; i--) {
            for (int j = 1; j <= m; j++) {
                if (grid[i - 1][j - 1] == 'E') {
                    d[i][j] = d[i + 1][j] + 1;
                } else if (grid[i - 1][j - 1] == '0') {
                    d[i][j] = d[i + 1][j];
                }
            }
        }
        
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (grid[i - 1][j - 1] != '0') continue;
                ans = max(ans, r[i][j] + l[i][j] + u[i][j] + d[i][j]);
            }
        }
        return ans;
    }
};
