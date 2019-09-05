class Solution {
public:
    int dp[105][105];
    int targetX, targetY;

    int dfs(int x, int y) {
        if (x > targetX || y > targetY) {
            return 0;
        }

        if (dp[x][y]) {
            return dp[x][y];
        }
        if(targetX == x && targetY == y) {
            return 1;
        }

        int answer = 0;
        answer += dfs(x + 1, y);
        answer += dfs(x, y + 1);
        return dp[x][y] = answer;
    }

    int uniquePaths(int m, int n) {
        if (m == 1 && n == 1) {
            return 1;
        }

        targetX = m;
        targetY = n;
        std::memset(dp, 0, sizeof(dp));

        return dfs(1, 1);
    }
};