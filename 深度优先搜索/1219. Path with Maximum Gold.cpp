class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        this->gold = grid;
        visited = vector<vector<bool>>(n, vector<bool>(m, false));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) continue;
                dfs(i, j, grid[i][j]);
            }
        }
        return ans;
    }
private:
    int n, m, ans = 0;
    vector<vector<bool>> visited;
    vector<vector<int>> gold;
    
    bool pointValid(int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    void dfs(int i, int j, int cur) {
        visited[i][j] = true;
        ans = max(ans, cur);
        
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        for (int k = 0; k < 4; k++) {
            const int nx = i + dx[k], ny = j + dy[k];
            if (pointValid(nx, ny) && !visited[nx][ny] && gold[nx][ny] != 0) dfs(nx, ny, cur + gold[nx][ny]);
        }
        visited[i][j] = false;
    }
};
