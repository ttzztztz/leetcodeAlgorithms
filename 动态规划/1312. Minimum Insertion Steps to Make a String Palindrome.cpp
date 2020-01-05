class Solution {
public:
    int minInsertions(string s) {
        const int N = s.size();
        vector<vector<int>> dp(N + 5, vector<int>(N + 5, -1));
        
        for (int i = 0; i < N; i++) {
            dp[i][i] = 1;
        }
        
        for (int i = 0; i + 1 < N; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = 2;
            } else {
                dp[i][i + 1] = 1;
            }
        }
        
        for (int len = 3; len <= N; len++) {
            for (int i = 0; i + len - 1 < N; i++) {
                const int j = i + len - 1;
                
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
                }
            }
        }
        
        return N - dp[0][N - 1];
    }
};
