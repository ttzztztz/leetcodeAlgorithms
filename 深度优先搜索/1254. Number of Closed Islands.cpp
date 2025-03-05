class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        n = grid.size(), m = grid[0].size();
        visited = vector<vector<bool>>(n, vector<bool>(m, false));

        int ans = 0;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0 && !visited[i][j] && dfs(grid, i, j)) {
                ans++;
            }
        }
        return ans;
    }
private:
    vector<vector<bool>> visited;
    int n, m;
    
    bool dfs(const vector<vector<int>>& grid, int i, int j) {
        visited[i][j] = true;

        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};

        bool ok = true;
        for (int k = 0; k < 4; k++) {
            const int nx = i + dx[k], ny = j + dy[k];
            if (!point_valid(nx, ny)) {
                ok = false;
                continue;
            }

            if (grid[nx][ny] == 0 && !visited[nx][ny] && !dfs(grid, nx, ny)) {
                ok = false;
            }
        }
        return ok;
    }

    bool point_valid(int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
};