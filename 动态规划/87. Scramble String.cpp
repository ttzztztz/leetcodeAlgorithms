class Solution {
public:
    bool isScramble(string s1, string s2) {
        const int N = s1.size(), M = s2.size();
        if (N != M) return false;
        
        vector<vector<vector<bool>>> dp(N + 1, vector<vector<bool>>(N, vector<bool>(N, false)));
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dp[1][i][j] = (s1[i] == s2[j]);
            }
        }
        
        for (int len = 2; len <= N; len++) {
            for (int i = 0; i + len - 1 < N; i++) {
                for (int j = 0; j + len - 1 < N; j++) {
                    for (int k = 1; k <= len; k++) {
                        dp[len][i][j] = 
                            dp[len][i][j] || 
                            (dp[k][i][j] && dp[len - k][i + k][j + k]) ||
                            (dp[k][i][j + len - k] && dp[len - k][i + k][j]);
                    }
                }
            }
        }
        
        return dp[N][0][0];
    }
};
