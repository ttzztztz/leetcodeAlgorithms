class Solution {
public:
    int findPaths(int n, int m, int maxMove, int startRow, int startColumn) {
        memset(f, 0xff, sizeof f);
        this->n = n, this->m = m;
        return dfs(maxMove, startRow, startColumn);
    }
private:
    int n, m;
    typedef long long ll;
    ll f[55][55][55];
    const int mod = 1e9+7;
    
    bool point_valid(int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    
    ll dfs(int remain, int i, int j) {
        if (!point_valid(i, j)) return 1;
        if (remain == 0) return 0;
        
        ll& val = f[remain][i][j];
        if (val != -1) return val;
        
        ll ans = 0;
        const int dx[] = { 0, 0, -1, 1 };
        const int dy[] = { -1, 1, 0, 0 };
        for (int k = 0; k < 4; k++) {
            const int nx = i + dx[k], ny = j + dy[k];
            ans = (ans + dfs(remain - 1, nx, ny)) % mod;
        }
        return val = ans;
    }
};