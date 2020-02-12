class Solution {
public:
    /**
     * @param costs: n x 3 cost matrix
     * @return: An integer, the minimum cost to paint all houses
     */
    int minCost(vector<vector<int>> &costs) {
        const int N = costs.size();
        vector<vector<int>> dp(N + 1, vector<int>(3, 999999));
        for (int i = 0; i < 3; i++) dp[0][i] = 0;
        
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (j == k) continue;
                    
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + costs[i - 1][j]);
                }
            }
        }
        
        
        int answer = 999999;
        for (int i = 0; i < 3; i++) {
            answer = min(answer, dp[N][i]);
        }
        return answer;
    }
};
