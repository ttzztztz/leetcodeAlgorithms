class Solution {
public:
    int dfs(vector<vector<vector<int>>>& dp, vector<vector<int>>& grid, int x1, int y1, int x2) {
        const int y2 = x1 + y1 - x2, N = grid.size();

        if (N <= x1 || N <= x2 || N <= y1 || N <= y2 || grid[x1][y1] == -1 || grid[x2][y2] == -1) {
            return -99999999;
        }
        if (dp[x1][x2][y1] != -1) {
            return dp[x1][x2][y1];
        }
        if (x1 == N - 1 && y1 == N - 1) {
            return grid[x1][y1];
        }

        int answer = 0;
        answer += grid[x1][y1];
        if (x1 != x2 && y1 != y2) {
            answer += grid[x2][y2];
        }
        answer += std::max(
                std::max(
                        dfs(dp, grid, x1 + 1, y1, x2),
                        dfs(dp, grid, x1, y1 + 1, x2 + 1)
                ),
                std::max(
                        dfs(dp, grid, x1 + 1, y1, x2 + 1),
                        dfs(dp, grid, x1, y1 + 1, x2)
                )
        );
        return dp[x1][x2][y1] = answer;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(55, vector<vector<int>>(55, vector<int>(55, -1)));

        return std::max(0, dfs(dp, grid, 0, 0, 0));
    }
};