class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        memset(f, 0xff, sizeof f);
        memset(c, 0, sizeof c);
        
        n = cost.size(), m = cost[0].size();
        mask = (1 << m) - 1;
        for (int i = 0; i < n; i++) for (int j = 0; j <= mask; j++) {
            for (int x = 0; x < m; x++) {
                if (j & (1 << x)) c[i][j] += cost[i][x];
            }
        }

        return dfs(0, 0);
    }
private:
    int f[12][(1 << 12) + 5], c[12][(1 << 12) + 5];
    int n, m, mask;
    const int inf = 0x3f3f3f3f;
    
    int dfs(int i, int state) {
        if (i == n) return (state == mask) ? 0 : inf;
        
        int& val = f[i][state];
        if (val != -1) return val;
        int ans = numeric_limits<int>::max();
        for (int j = 0; j < m; j++) {
            ans = min(ans, c[i][1 << j] + dfs(i + 1, state | (1 << j)));
        }
        
        const int t = mask & (~state);
        for (int nxt = t; nxt; nxt = (nxt - 1) & mask) {
            ans = min(ans, c[i][nxt] + dfs(i + 1, state | nxt));
        }
        return val = ans;
    }
};