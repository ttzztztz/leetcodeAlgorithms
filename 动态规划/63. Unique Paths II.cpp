class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty()) return 0;
        const int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        if (obstacleGrid[n - 1][m - 1] == 1 || obstacleGrid[0][0] == 1) return 0;
        
        typedef long long ll;
        vector<ll> f(m + 1, 0);
        f[m - 1] = 1;
        for (int i = n - 1; i >= 0; i--) {
            vector<ll> g(m + 1, 0);
            for (int j = m - 1; j >= 0; j--) {
                if (obstacleGrid[i][j] == 1) continue;
                
                g[j] += (f[j] + g[j + 1]);
            }
            f = g;
        }
        return f[0];
    }
};