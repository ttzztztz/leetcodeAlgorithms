class Solution {
public:
    int numOfWays(int n) {
        memset(f, 0xff, sizeof f);
        this->N = n;
        
        long long answer = 0;
        for (int i = 0; i <= 2; i++) {
            for (int j = 0; j <= 2; j++) {
                for (int k = 0; k <= 2; k++) {
                    if (i == j || j == k) continue;
                    answer += dfs(1, i, j, k);
                    answer %= MOD;
                }
            }
        }
        return answer;
    }
private:
    int N;
    long long f[5005][5][5][5];
    const int GREEN = 0, RED = 1, BLUE = 2, MOD = 1e9+7;
    bool valid(int last1, int last2, int last3, int cur1, int cur2, int cur3) {
        if (cur1 == last1) return false;
        if (cur2 == cur1 || cur2 == last2) return false;
        if (cur3 == cur2 || cur3 == last3) return false;
        
        return true;
    }
    long long dfs(int i, int last1, int last2, int last3) {
        if (i == N) return 1;
        if (f[i][last1][last2][last3] != -1) return f[i][last1][last2][last3];
        
        long long answer = 0;
        for (int c = 0; c <= 2; c++) {
            for (int j = 0; j <= 2; j++) {
                for (int k = 0; k <= 2; k++) {
                    if (valid(last1, last2, last3, c, j, k)) {
                        answer += dfs(i + 1, c, j, k);
                        answer %= MOD;
                    }
                }
            }
        }
        return f[i][last1][last2][last3] = answer;
    }
};
