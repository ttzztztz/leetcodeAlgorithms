class Solution {
public:
    /**
     * @param flights: the airline status from the city i to the city j
     * @param days: days[i][j] represents the maximum days you could take vacation in the city i in the week j
     * @return: the maximum vacation days you could take during K weeks
     */
    int maxVacationDays(vector<vector<int>> &flights, vector<vector<int>> &days) {
        const int K = flights.size(), N = days[0].size();
        
        // N 天, K 个城市
        vector<vector<int>> dp(N + 1, vector<int>(K, -999999));
        dp[0][0] = 0;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < K; j++) {
                if (dp[i][j] <= -999999) continue;
                
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + days[j][i]);
                for (int n = 0; n < K; n++) {
                    if (flights[j][n] == 1) {
                        dp[i + 1][n] = max(dp[i + 1][n], dp[i][j] + days[n][i]);
                    }
                }
            }
        }
        
        int answer = 0;
        for (int i = 0; i < K; i++) {
            answer = max(dp[N][i], answer);
        }
        return answer;
    }
};
