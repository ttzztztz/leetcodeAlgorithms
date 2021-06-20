class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        memset(visited, 0, sizeof visited);
        n = grid1.size(), m = grid1[0].size();
        
        int cnt = 0;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            if (visited[i][j] || grid1[i][j] == 0) continue;
            dfs1(grid1, i, j, ++cnt);
        }
        
        memset(visited, 0, sizeof visited);
        int ans = 0;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            if (visited[i][j] || grid1[i][j] == 0 || grid2[i][j] == 0) continue;
            
            if (dfs2(grid1, grid2, i, j, grid1[i][j])) {
                ans++;
            }
        }
        return ans;
    }
private:
    bool visited[501][501];
    int n, m;
    
    bool point_valid(int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    
    void dfs1(vector<vector<int>>& g, int i, int j, int color) {
        visited[i][j] = true;
        g[i][j] = color;
        
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        for (int k = 0; k < 4; k++) {
            const int nx = i + dx[k], ny = j + dy[k];
            if (point_valid(nx, ny) && !visited[nx][ny] && g[nx][ny] == 1) dfs1(g, nx, ny, color);
        }
    }
    
    bool dfs2(vector<vector<int>>& g1, vector<vector<int>>& g2, int i, int j, int color) {
        visited[i][j] = true;
        bool ok = true;
        if (g1[i][j] != color) ok = false;
        
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        
        for (int k = 0; k < 4; k++) {
            const int nx = i + dx[k], ny = j + dy[k];
            if (point_valid(nx, ny) && !visited[nx][ny] && g2[nx][ny] != 0) {
                if (!dfs2(g1, g2, nx, ny, color)) ok = false;
            }
        }
        return ok;
    }
};
