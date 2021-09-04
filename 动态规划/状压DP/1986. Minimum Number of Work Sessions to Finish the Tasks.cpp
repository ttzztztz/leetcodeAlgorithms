class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        memset(f, 0xff, sizeof f);
        this->tasks = tasks;
        this->sess = sessionTime;
        this->n = tasks.size();
        
        return dfs(0, sessionTime);
    }
private:
    int f[(1 << 14) + 5][16];
    vector<int> tasks;
    int sess, n;
    
    int dfs(int state, int rest) {
        if (state == (1 << n) - 1) return (rest == sess) ? 0 : 1;
        int& val = f[state][rest];
        if (val != -1) return val;
        
        int ans = n + 5;
        for (int k = 0; k < n; k++) {
            if (state & (1 << k)) continue;
            
            if (rest >= tasks[k]) {
                ans = min(ans, dfs(state | (1 << k), rest - tasks[k]));
            } else {
                ans = min(ans, 1 + dfs(state | (1 << k), sess - tasks[k]));
            }
        }
        return val = ans;
    }
};