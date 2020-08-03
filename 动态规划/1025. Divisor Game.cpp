class Solution {
public:
    bool divisorGame(int N) {
        memset(f, 0xff, sizeof f);
        return dfs(N, 0);
    }
private:
    int f[1005][2];
    int dfs(int n, int turn) {
        if (n <= 1) return turn == 0 ? 0 : 1;
        int& val = f[n][turn];
        if (val != -1) return val;
        
        int answer = (turn == 0) ? 0 : 1;
        
        for (int i = 1; i < n; i++) {
            if (n % i != 0) continue;
            
            if (turn == 0) { // alice
                if (dfs(n - i, turn ^ 1) == 1) return val = 1;
            } else { // bob
                if (dfs(n - i, turn ^ 1) == 0) return val = 0;
            }
        }
        
        return val = answer;
    }
};