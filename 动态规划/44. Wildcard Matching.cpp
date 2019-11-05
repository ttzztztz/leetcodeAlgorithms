class Solution {
public:
    bool isMatch(string s, string p) {
        const int S = s.size(), P = p.size();
        vector<vector<bool>> dp(S + 1, vector<bool>(P + 1, false));

        dp[0][0] = true;
        for (int i = 1; i <= P; i++) {
            dp[0][i] = dp[0][i - 1] && p[i - 1] == '*';
        }

        for (int i = 1; i <= S; i++) {
            for (int j = 1; j <= P; j++) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }

        return dp[S][P];
    }
};