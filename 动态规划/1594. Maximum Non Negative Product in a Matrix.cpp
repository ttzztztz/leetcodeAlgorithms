class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        this->g = grid;
        this->n = grid.size(), m = grid[0].size();
        
        memset(f, 0, sizeof f);
        memset(h, 0xff, sizeof h);
        
        long long ans = dfs(0, 0, 0);
        if (ans < 0) return -1;
        else return ans % mod;
    }
private:
    vector<vector<int>> g;
    int n, m;
    long long f[20][20][2];
    int h[20][20][2];
    
    const int mod = 1e9+7;
    
    bool pointValid(int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    
    long long dfs(int i, int j, int state) { 
        // state == 0 : max
        // state == 1 : min
        if (i == n - 1 && j == m - 1) return g[i][j];
        long long& val = f[i][j][state];
        if (h[i][j][state] != -1) return val;
        
        long long ans;
        if (state == 0) ans = numeric_limits<long long>::min();
        else ans = numeric_limits<long long>::max();
        
        const int dx[] = {0, 1};
        const int dy[] = {1, 0};
        
        for (int k = 0; k < 2; k++) {
            const int nx = i + dx[k], ny = j + dy[k];
            if (!pointValid(nx, ny)) continue;
            
            if (state == 0) { // max
                if (g[i][j] >= 0) {
                    ans = max(ans, g[i][j] * dfs(nx, ny, state));
                } else {
                    ans = max(ans, g[i][j] * dfs(nx, ny, state ^ 1));
                }
                
            } else {
                if (g[i][j] >= 0) {
                    ans = min(ans, g[i][j] * dfs(nx, ny, state));
                } else {
                    ans = min(ans, g[i][j] * dfs(nx, ny, state ^ 1));
                }
            }
        }
        
        h[i][j][state] = 1;
        return val = ans;
    }
};
