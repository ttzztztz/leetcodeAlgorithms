class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        memset(visited, 0, sizeof visited);
        this->grid = grid;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(i, j, -1, -1)) return true;
            }
        }
        return false;
    }
private:
    int n, m;
    bool visited[505][505];
    vector<vector<char>> grid;
    
    bool pointValid(int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    
    bool dfs(int i, int j, int pi, int pj) {
        if (visited[i][j]) return false;
        visited[i][j] = true;
        
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        
        for (int k = 0; k < 4; k++) {
            const int nx = dx[k] + i, ny = dy[k] + j;
            
            if (pointValid(nx, ny) && grid[nx][ny] == grid[i][j]) {
                if (nx == pi && ny == pj) continue;
                
                if (visited[nx][ny] || dfs(nx, ny, i, j)) return true;
            }
        }
        
        return false;
    }
};
