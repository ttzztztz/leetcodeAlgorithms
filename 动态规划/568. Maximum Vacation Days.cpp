class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        if (days.empty()) return 0;
        const int n = days.size(), k = days[0].size();
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
        dp[0][0] = 0;
        
        for (int i = 0; i < n; i++) flights[i][i] = 1;
        for (int i = 1; i <= k; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (flights[k][j] == 0 || dp[i - 1][k] == -1) continue;
                    
                    dp[i][j] = max(dp[i][j], dp[i - 1][k] + days[j][i - 1]);
                }
            }
        }
        return *max_element(dp[k].begin(), dp[k].end());
    }
};
