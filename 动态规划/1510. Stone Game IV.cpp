class Solution {
public:
    int f[100005][2];
    vector<int> pre;
    void init() {
        for (int i = 1; i * i <= 100000; i++) {
            pre.push_back(i * i);
        }
    }
    bool winnerSquareGame(int n) {
        memset(f, 0xff, sizeof f);
        init();
        
        return dfs(n, 0);
    }
    int dfs(int n, int turn) { // turn 0->alice, 1->bob
        if (n == 0) return (turn == 0) ? 0 : 1;
        int& val = f[n][turn];
        if (val != -1) return val;
        
        if (turn == 0) { // alice
            int answer = 0;
            for (int k = 0; k < pre.size(); k++) {
                if (n - pre[k] < 0) break;
                if (dfs(n - pre[k], turn ^ 1) == 1) return val = 1;
            }
            return val = 0;
        } else { // bob
            int answer = 0;
            for (int k = 0; k < pre.size(); k++) {
                if (n - pre[k] < 0) break;
                if (dfs(n - pre[k], turn ^ 1) == 0) return val = 0;
            }
            return val = 1;
        }
        
    }
};