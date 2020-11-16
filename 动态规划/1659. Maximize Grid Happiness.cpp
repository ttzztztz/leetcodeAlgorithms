class Solution {
public:
    int getMaxGridHappiness(int n, int m, int introvertsCount, int extrovertsCount) {
        memset(f, 0xff, sizeof f);
        this->n = n, this->m = m;
        return dfs(0, introvertsCount, extrovertsCount, 0, 0);
    }
private:
    int n, m;
    int mask = 63;
    int f[25][7][7][64][64];
    
    int delta(int d, int pos, int i_state, int e_state) {
        int ans = 0;
        const int i = pos / m, j = pos % m;
        if (j - 1 >= 0) {
            if (i_state & 1) ans += d - 30;
            if (e_state & 1) ans += d + 20;
        }
        
        if (i - 1 >= 0) {
            const int up = (1 << (m - 1));
            if (i_state & up) ans += d - 30;
            if (e_state & up) ans += d + 20;
        }
        return ans;
    }
    
    int dfs(int pos, int i_count, int e_count, int i_state, int e_state) {
        if (pos == n * m) return 0;
        int& val = f[pos][i_count][e_count][i_state][e_state];
        if (val != -1) return val;
        
        const int i_next_state = (i_state << 1) & mask, e_next_state = (e_state << 1) & mask;
        int ans = dfs(pos + 1, i_count, e_count, i_next_state, e_next_state);
        
        if (i_count > 0) {
            ans = max(ans, 120 + delta(-30, pos, i_state, e_state) + dfs(pos + 1, i_count - 1, e_count, i_next_state | 1, e_next_state));
        }
        
        if (e_count > 0) {
            ans = max(ans, 40 + delta(20, pos, i_state, e_state) + dfs(pos + 1, i_count, e_count - 1, i_next_state, e_next_state | 1));
        }
        
        return val = ans;
    }
};
