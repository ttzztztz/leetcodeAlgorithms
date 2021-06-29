class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        this->grid = grid;
        if (grid.empty()) return 0;
        
        n = grid.size(), m = grid[0].size();
        memset(f, 0x3f, sizeof f);

        ll ans = dfs(0, 0, 0);
        if (ans < 0) return -1;
        else return ans % mod;
    }
private:
    typedef long long ll;
    ll f[16][16][2];
    int n, m;
    const ll initial = 0x3f3f3f3f3f3f3f3f;
    const int mod = 1e9+7;
    vector<vector<int>> grid;
    
    ll dfs(int i, int j, int state) {
        if (i == n - 1 && j == m - 1) {
            return grid[i][j];
        }

        // state = 0 -> max
        // state = 1 -> min
        ll& val = f[i][j][state];
        if (val != initial) return val;
        
        const int dx[] = {0, 1};
        const int dy[] = {1, 0};
        
        ll ans;
        if (state == 0) {
            ans = numeric_limits<int>::min();
            for (int k = 0; k < 2; k++) {
                const int nx = i + dx[k], ny = j + dy[k];
                if (nx >= n || ny >= m) continue;
                
                ans = max(ans, max(
                    1ll * grid[i][j] * dfs(nx, ny, 0),
                    1ll * grid[i][j] * dfs(nx, ny, 1)
                ));
            }
        } else { // state == 1
            ans = numeric_limits<int>::max();
            for (int k = 0; k < 2; k++) {
                const int nx = i + dx[k], ny = j + dy[k];
                if (nx >= n || ny >= m) continue;
                
                ans = min(ans, min(
                    1ll * grid[i][j] * dfs(nx, ny, 0),
                    1ll * grid[i][j] * dfs(nx, ny, 1)
                ));
            }
        }
        return val = ans;
    }
};