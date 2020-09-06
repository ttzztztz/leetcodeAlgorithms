class Solution {
public:
    /**
     * @param maxChoosableInteger: a Integer
     * @param desiredTotal: a Integer
     * @return: if the first player to move can force a win
     */
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal) return true;
        const int sum = (maxChoosableInteger + 1) * maxChoosableInteger / 2;
        if (sum < desiredTotal) return false;
        
        memset(f, 0xff, sizeof f);
        this->m = maxChoosableInteger;
        this->d = desiredTotal;
        
        return dfs(0, 0);
    }
private:
    int f[1200000][2];
    int m, d;
    int dfs(int state, int turn) {
        int& val = f[state][turn];
        if (val != -1) return val;
        
        int sum = 0;
        for (int i = 0; i < m; i++) {
            if (state & (1 << i)) sum += i + 1;
        }
        if (sum >= d) return val = (turn == 1 ? 1 : 0);
        
        int answer = 0;
        if (turn == 0) { // first hand
            answer = 0;
            for (int i = 0; i < m; i++) {
                if (!(state & (1 << i)) && dfs(state | (1 << i), turn ^ 1) == 1) {
                    return val = 1;
                }
            }
        } else { // second hand
            answer = 1;
            for (int i = 0; i < m; i++) {
                if (!(state & (1 << i)) && dfs(state | (1 << i), turn ^ 1) == 0) {
                    return val = 0;
                }
            }
        }
        return val = answer;
    }
};
