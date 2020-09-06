class Solution {
public:
    /**
     * @param symb: the array of symbols
     * @param oper: the array of operators
     * @return: the number of ways
     */
    int countParenth(string &symb, string &oper) {
        const int N = symb.size();
        if (N == 0) return 0;
        
        vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(N + 1, vector<int>(2, 0)));
        
        for (int i = 0; i < N; i++) {
            dp[i][i][1] = (symb[i] == 'T');
            dp[i][i][0] = (symb[i] == 'F');
        }
        
        for (int len = 2; len <= N; len++) {
            for (int i = 0; i + len - 1 < N; i++) {
                const int j = i + len - 1;
                for (int k = i; k + 1 <= j; k++) {
                    if (oper[k] == '&') {
                        dp[i][j][1] += dp[i][k][1] * dp[k + 1][j][1];
                        dp[i][j][0] += dp[i][k][0] * dp[k + 1][j][0];
                        dp[i][j][0] += dp[i][k][0] * dp[k + 1][j][1];
                        dp[i][j][0] += dp[i][k][1] * dp[k + 1][j][0];
                    } else if (oper[k] == '|') {
                        dp[i][j][1] += dp[i][k][1] * dp[k + 1][j][1];
                        dp[i][j][0] += dp[i][k][0] * dp[k + 1][j][0];
                        dp[i][j][1] += dp[i][k][0] * dp[k + 1][j][1];
                        dp[i][j][1] += dp[i][k][1] * dp[k + 1][j][0];
                    } else if (oper[k] == '^') {
                        dp[i][j][0] += dp[i][k][1] * dp[k + 1][j][1];
                        dp[i][j][0] += dp[i][k][0] * dp[k + 1][j][0];
                        dp[i][j][1] += dp[i][k][0] * dp[k + 1][j][1];
                        dp[i][j][1] += dp[i][k][1] * dp[k + 1][j][0];
                    }
                }
            }
        }
        
        return dp[0][N - 1][1];
    }
};
