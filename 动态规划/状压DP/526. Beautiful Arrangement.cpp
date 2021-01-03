class Solution {
public:
    int countArrangement(int n) {
        this->n = n;
        memset(f, 0xff, sizeof f);
        return dfs(0, 0);
    }
private:
    int n;
    int f[1 << 15][16];
    
    int dfs(int state, int number) {
        if (state == (1 << n) - 1) return 1;
        int& val = f[state][number];
        if (val != -1) return val;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!(state & (1 << i)) && ((number + 1) % (i + 1) == 0 || (i + 1) % (number + 1) == 0)) {
                ans += dfs(state | (1 << i), number + 1);
            }
        }
        return val = ans;
    }
};
