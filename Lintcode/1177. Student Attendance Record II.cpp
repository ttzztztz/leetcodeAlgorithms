class Solution {
public:
    /**
     * @param n: an integer
     * @return: return an integer
     */
    int checkRecord(int n) {
        vector<vector<long long>> dp(2, vector<long long>(3, 0));
        dp[0][0] = 1;
        const int MOD = 1000000007;
        
        for (int i = 1; i <= n; i++) {
            vector<vector<long long>> next(2, vector<long long>(3, 0));
            // 'A'
            next[1][0] += dp[0][0] + dp[0][1] + dp[0][2];
            next[1][0] %= MOD;
            // 'L'
            next[0][1] += dp[0][0];
            next[0][1] %= MOD;
            
            next[0][2] += dp[0][1];
            next[0][2] %= MOD;
            
            next[1][1] += dp[1][0];
            next[1][1] %= MOD;
            
            next[1][2] += dp[1][1];
            next[1][2] %= MOD;
            // 'P'
            next[0][0] +=  dp[0][0] + dp[0][1] + dp[0][2];
            next[0][0] %= MOD;
            
            next[1][0] += dp[1][0] + dp[1][1] + dp[1][2];
            next[1][0] %= MOD;
            
            dp = next;
        }
        
        long long answer = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                answer += dp[i][j];
                answer %= MOD;
            }
        }
        return answer;
    }
};
