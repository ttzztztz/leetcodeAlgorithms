class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int ans = 0;
        visited = vector<vector<bool>>(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                ans = max(ans, dfs(grid, i, j));
            }
        }
        return ans;
    }
private:
    int n, m;
    vector<vector<bool>> visited;

    bool point_valid(int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    int dfs(const vector<vector<int>>& grid, int i, int j) {
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};

        int cur = 1;
        visited[i][j] = true;
        for (int k = 0; k < 4; k++) {
            const int ni = i + dx[k], nj = j + dy[k];
            if (point_valid(ni, nj) && !visited[ni][nj] && grid[ni][nj] == 1) {
                cur += dfs(grid, ni, nj);
            }
        }
        return cur;
    }
};