class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int ans = 0;
        n = matrix.size(), m = matrix[0].size();
        memo = vector<vector<int>>(n, vector<int>(m, -1));

        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            ans = max(ans, dfs(matrix, i, j));
        }
        return ans;
    }
private:
    int n, m;
    vector<vector<int>> memo;

    bool point_valid(int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    int dfs(const vector<vector<int>>& matrix, int i, int j) {
        if (memo[i][j] != -1) return memo[i][j];

        int ans = 1;
        const int dx[] = { 1, -1, 0, 0 };
        const int dy[] = { 0, 0, -1, 1 };
        for (int k = 0; k < 4; k++) {
            const int nx = i + dx[k], ny = j + dy[k];
            if (!point_valid(nx, ny) || matrix[i][j] >= matrix[nx][ny]) continue;
            ans = max(ans, 1 + dfs(matrix, nx, ny));
        }
        return memo[i][j] = ans;
    }
};