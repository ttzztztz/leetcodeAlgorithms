class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        
        this->grid = grid;
        n = grid.size(), m = grid[0].size();
        visited = vector<vector<bool>>(n, vector<bool>(m, false));
        
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                cur = 0;
                dfs(i, j);
                ans = max(ans, cur);
            }
        }
        return ans;
    }
private:
    int ans = 0, cur = 0;
    int n, m;
    vector<vector<bool>> visited;
    vector<vector<int>> grid;
    
    bool point_valid(int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    
    void dfs(int i, int j) {
        visited[i][j] = true;
        
        cur++;
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        for (int k = 0; k < 4; k++) {
            const int nx = i + dx[k], ny = j + dy[k];
            if (!point_valid(nx, ny) || visited[nx][ny] || grid[nx][ny] == 0) continue;
            
            dfs(nx, ny);
        }
    }
};