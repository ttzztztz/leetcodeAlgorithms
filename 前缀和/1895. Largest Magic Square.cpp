class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        const int n = grid.size(), m = grid[0].size();
        
        int f[n + 1][m + 1], g[n + 1][m + 1];
        memset(f, 0, sizeof f);
        memset(g, 0, sizeof g);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                f[i][j] = (j >= 1 ? f[i][j - 1] : 0) + grid[i][j];
                g[i][j] = (i >= 1 ? g[i - 1][j] : 0) + grid[i][j];
            }
        }
        
        for (int len = min(n, m); len >= 1; len--) {
            for (int i = 0; i + len - 1 < n; i++) for (int j = 0; j + len - 1 < m; j++) {
                int last = f[i][j + len - 1] - (j >= 1 ? f[i][j - 1] : 0);
                bool ok = true;
                for (int x = 0; x < len; x++) {
                    int t = f[i + x][j + len - 1] - (j >= 1 ? f[i + x][j - 1] : 0);
                    if (t != last) {
                        ok = false;
                        break;
                    }
                }
                
                for (int x = 0; x < len; x++) {
                    int t = g[i + len - 1][j + x] - (i >= 1 ? g[i - 1][j + x] : 0);
                    if (t != last) {
                        ok = false;
                        break;
                    }
                }
                
                int s1 = 0, s2 = 0;
                for (int x = 0; x < len; x++) {
                    s1 += grid[i + x][j + x];
                }
                for (int x = 0; x < len; x++) {
                    s2 += grid[i + x][j + len - 1 - x];
                }
                
                if (s1 != last || s2 != last) continue;
                if (ok) return len;
            }
        }
        return 1;
    }
};