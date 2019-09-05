class Solution {
public:
    unsigned int dp[105][105];
    int targetX, targetY;

    unsigned int dfs(vector<vector<int>>& obstacleGrid, int x, int y) {
        if (x > targetX || y > targetY || obstacleGrid[x - 1][y - 1] == 1) {
            return 0;
        }

        if (dp[x][y] != -1) {
            return dp[x][y];
        }

        if(targetX == x && targetY == y) {
            return 1;
        }

        unsigned int answer = 0;
        answer += dfs(obstacleGrid, x + 1, y);
        answer += dfs(obstacleGrid, x, y + 1);
        return dp[x][y] = answer;
    }

    unsigned int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        targetX = m;
        targetY = n;
        std::memset(dp, 0xff, sizeof(dp));

        return dfs(obstacleGrid, 1, 1);
    }
};