class Solution {
public:
    int numberOfPatterns(int m, int n) {
        memset(f, 0xff, sizeof f);
        lower = m, upper = n;
        
        int ans = 0;
        for (int i = 0; i < 9; i++) ans += dfs(1 << i, i);
        return ans;
    }
private:
    int lower, upper;
    int f[(1 << 9) + 5][10];
    const vector<pair<int, int>> pos = {
        {0, 0},
        {0, 1},
        {0, 2},
        {1, 0},
        {1, 1},
        {1, 2},
        {2, 0},
        {2, 1},
        {2, 2}
    };
    
    const vector<vector<int>> grid = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8}
    };
    
    int bit_cnt(int i) {
        int ans = 0;
        while (i) {
            ans++;
            i -= (i & (-i));
        }
        return ans;
    }
    
    bool point_valid(int x, int y) {
        return x >= 0 && y >= 0 && x <= 2 && y <= 2;
    }
    
    bool can_reach(const pair<int, int>& from, const pair<int, int>& to, int state) {
        auto [x1, y1] = from;
        auto [x2, y2] = to;
        
        const int d1 = x2 - x1, d2 = y2 - y1;
        const int dx[] = {-2, -2, 2, 2, 0, 0, 2, -2};
        const int dy[] = {-2, 2, -2, 2, 2, -2, 0, 0};
        for (int k = 0; k < 8; k++) {
            if (d1 == dx[k] && d2 == dy[k]) {
                const int middle = grid[x1 + d1 / 2][y1 + d2 / 2];
                return state & (1 << middle);
            }
        }
        return true;
    }
    
    int dfs(int state, int last) {
        if (bit_cnt(state) > upper) return 0;
        int& val = f[state][last];
        if (val != -1) return val;
        int ans = 0;
        
        if (bit_cnt(state) >= lower && bit_cnt(state) <= upper) ans++;
        auto [x, y] = pos[last];
        for (int dx = -2; dx <= 2; dx++) {
            for (int dy = -2; dy <= 2; dy++) {
                const int nx = x + dx, ny = y + dy;
                if (!point_valid(nx, ny) || !can_reach({x, y}, {nx, ny}, state)) continue;
                
                const int nxt = grid[nx][ny];
                if (!(state & (1 << nxt))) {
                    ans += dfs(state | (1 << nxt), nxt);
                }
            }
        }
        return val = ans;
    }
};
