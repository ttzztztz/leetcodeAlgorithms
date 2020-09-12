class Solution {
public:
    /**
     * @param grid: a grid
     * @return: the maximum number of cherries possible
     */
    int cherryPickup(vector<vector<int>> &grid) {
        int f[105][55][55];
        const int n = grid.size(), inf = 0xffffffff;
        memset(f, 0xff, sizeof f);
        f[0][0][0] = 0;

        for (int i = 0; i < 2 * n - 2; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    const int a = i - j, b = i - k;
                    
                    if (grid[j][a] == -1 || grid[k][b] == -1) continue;
                    int& val = f[i][j][k];
                    if (val == -1) continue;
                    if (grid[j][a] != -1) val += grid[j][a];
                    if (grid[k][b] != -1 && !(j == k && a == b)) val += grid[k][b];
                    
                    if (val == inf) continue;
                    f[i + 1][j][k] = max(f[i + 1][j][k], val);
                    f[i + 1][j + 1][k] = max(f[i + 1][j + 1][k], val);
                    f[i + 1][j][k + 1] = max(f[i + 1][j][k + 1], val);
                    f[i + 1][j + 1][k + 1] = max(f[i + 1][j + 1][k + 1], val);
                }
            }
        }
        
        if (f[2 * n - 2][n - 1][n - 1] == -1) return 0;
        else return f[2 * n - 2][n - 1][n - 1] + grid[n - 1][n - 1];
    }
};
