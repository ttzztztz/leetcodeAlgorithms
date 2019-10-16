class Solution {
public:
    int dp[51][51][51];
    const int MOD = 1000000007;
    int m, n;
    bool pointValid(int x, int y) {
        return x >= 0 && y >= 0 && x < m && y < n;
    }
    int dfs(int x, int y, int rest) {
        if (!pointValid(x, y)) {
            return 1;
        }
        if (rest == 0) {
            return 0;
        }
        if (dp[x][y][rest] != -1) {
            return dp[x][y][rest];
        }

        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {1, -1, 0, 0};

        int answer = 0;
        for (int i = 0; i < 4; i++) {
            const int nextX = x + dx[i], nextY = y + dy[i];

            answer = (answer + dfs(nextX, nextY, rest - 1) % MOD) % MOD;
        }
        return dp[x][y][rest] = answer;
    }
    int findPaths(int m, int n, int N, int i, int j) {
        this->m = m, this->n = n;
        std::memset(dp, 0xff, sizeof(dp));

        return dfs(i, j, N);
    }
};