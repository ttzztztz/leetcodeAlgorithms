class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    a.emplace_back(i, j);
                }
            }
        }
        
        if (a.empty() || !ok(grid, -1, -1)) return 0;
        for (auto& p : a) {
            int i, j;
            tie(i, j) = p;
            
            grid[i][j] = 0;
            if (!ok(grid, i, j)) {
                return 1;
            }
            grid[i][j] = 1;
        }
        return 2;
    }
private:
    typedef pair<int, int> PII;
    vector<PII> a;
    int n, m;
    
    bool visited[35][35];
    int ans = 0;
    bool ok(const vector<vector<int>>& grid, int di, int dj) {
        memset(visited, 0, sizeof visited);
        ans = 0;
        
        for (auto& p : a) {
            if (!(p.first == di && p.second == dj)) {
                dfs(grid, p.first, p.second);
                break;
            }
        }
        
        if (di == -1 && dj == -1) return ans == a.size();
        else return ans == a.size() - 1;
    }
    
    bool pointValid(int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    
    void dfs(const vector<vector<int>>& grid, int i, int j) {
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        
        if (grid[i][j] != 1) return;
        visited[i][j] = true;
        ans++;
        
        for (int k = 0; k < 4; k++) {
            const int nx = i + dx[k], ny = j + dy[k];
            if (!pointValid(nx, ny)) continue;
            
            if (grid[nx][ny] == 1 && !visited[nx][ny]) {
                visited[nx][ny] = true;
                dfs(grid, nx, ny);
            }
        }
    }
};