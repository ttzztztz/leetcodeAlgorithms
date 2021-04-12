class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        this->grid = grid;
        if (grid.empty()) return 0;
        this->n = grid.size(), this->m = grid[0].size();
        visited = vector<vector<bool>>(n, vector<bool>(m, false));
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == 0 && dfs(i, j)) {
                    ans++;
                }
            }
        }
        return ans;
    }
private:
    vector<vector<int>> grid;
    vector<vector<bool>> visited;
    int n, m;
    
    bool point_valid(int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    
    bool dfs(int i, int j) {
        if (grid[i][j] == 1) { // water
            return true;
        }
        // land
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        visited[i][j] = true;
        bool ok = true;
        for (int k = 0; k < 4; k++) {
            const int nx = i + dx[k], ny = j + dy[k];
            if (!point_valid(nx, ny)) {
                ok = false;
                continue;
            }
            if (grid[nx][ny] == 0 && !visited[nx][ny]) {
                const int res = dfs(nx, ny);
                if (!res) ok = false;
            }
        }
        return ok;
    }
};