class Solution {
public:
    int solve(vector<vector<int>> &flights, vector<vector<int>> &days) {
        const int N = flights.size(), K = days.size();
        vector<vector<int>> dp(K + 5, vector<int>(N + 5, -9999999));
        dp[0][0] = 0;

        for (int i = 0; i < K; i++) {
            for (int j = 0; j < N; j++) {
                if (dp[i][j] <= -9999999) continue;

                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + days[j][i]);
                for (int v = 0; v < N; v++) {
                    if (flights[j][v] == 0) continue;

                    dp[i + 1][v] = max(dp[i + 1][v], dp[i][j] + days[i][v]);
                }
            }
        }

        int answer = 0;
        for (int i = 0; i < N; i++) answer = max(answer, dp[K][i]);
        return answer;
    }
};
