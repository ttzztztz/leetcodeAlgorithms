class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        n = grid.size(), m = grid[0].size();

        visited = vector<vector<bool>>(n, vector<bool>(m, false));
        int ans = 0;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            if (visited[i][j] || grid[i][j] != '1') continue;

            dfs(grid, i, j);
            ans++;
        }
        return ans;
    }
private:
    vector<vector<bool>> visited;
    int n, m;

    bool point_valid(int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    void dfs(const vector<vector<char>>& grid, int i, int j) {
        visited[i][j] = true;

        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        for (int k = 0; k < 4; k++) {
            const int nx = i + dx[k], ny = j + dy[k];
            if (!point_valid(nx, ny) || grid[nx][ny] != '1' || visited[nx][ny]) continue;

            dfs(grid, nx, ny);
        }
    }
};