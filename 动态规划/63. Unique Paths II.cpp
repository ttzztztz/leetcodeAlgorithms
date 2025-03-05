class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty()) return 0;
        const int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        if (obstacleGrid[n - 1][m - 1] == 1) return 0;

        typedef long long ll;
        vector<vector<ll>> f(n, vector<ll>(m, 0));
        for (int i = n - 1; i >= 0; i--) for (int j = m - 1; j >= 0; j--) {
            if (i == n - 1 && j == m - 1) {
                f[i][j] = 1;
                continue;
            }

            if (obstacleGrid[i][j] == 1) continue;
            if (i + 1 < n && obstacleGrid[i + 1][j] != 1) f[i][j] += f[i + 1][j];
            if (j + 1 < m && obstacleGrid[i][j + 1] != 1) f[i][j] += f[i][j + 1];
        }
        return f[0][0];
    }
};