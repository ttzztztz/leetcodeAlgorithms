class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        const int N = s1.size(), M = s2.size();
        vector<vector<int>> dp(N + 5, vector<int>(M + 5, 0));
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + s1[i - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int answer = 0;


        for (int i = 0; i < N; i++) {
            answer += s1[i];
        }
        for (int i = 0; i < M; i++) {
            answer += s2[i];
        }

        return answer - 2 * dp[N][M];
    }
};