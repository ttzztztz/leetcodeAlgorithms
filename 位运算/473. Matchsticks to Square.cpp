class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        this->matchsticks = matchsticks;
        n = matchsticks.size(), sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        mask = (1 << n) - 1;
        if (sum % 4 != 0) return false;
        
        per = sum / 4;
        memset(f, 0xff, sizeof f);
        for (int i = 1; i < (1 << n); i++) {
            if (acc(i) == per && dfs(1, i)) return true;
        }
        return false;
    }
private:
    vector<int> matchsticks;
    int f[4][(1 << 15)];
    int per = 0, n = 0, sum = 0, mask = 0;

    int acc(int state) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (state & (1 << i)) ans += matchsticks[i];
        }
        return ans;
    }
    
    bool dfs(int idx, int state) {
        if (idx == 3) {
            const int t = mask & (~state);
            return acc(t) == per;
        }
        if (state == mask) return false;
        
        int& val = f[idx][state];
        if (val != -1) return val;
        
        int ans = 0;
        const int super = mask & (~state);
        for (int i = super; i; i = (i - 1) & super) {
            if (acc(i) == per && dfs(idx + 1, state | i)) {
                ans = 1;
                break;
            }
        }
        return val = ans;
    }
};