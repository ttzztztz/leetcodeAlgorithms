class Solution {
public:
    /**
     * @param costs: n x k cost matrix
     * @return: an integer, the minimum cost to paint all houses
     */
    int minCostII(vector<vector<int>> &costs) {
        if (costs.size() == 0) return 0;
        
        const int N = costs.size(), K = costs[0].size();
        vector<vector<int>> dp(N + 1, vector<int>(K + 2, 999999));
        vector<vector<int>> f(N + 1, vector<int>(K + 2, 999999));
        vector<vector<int>> g(N + 1, vector<int>(K + 2, 999999));
        
        for (int i = 1; i <= K; i++) dp[0][i] = f[0][i] = g[0][i] = 0;
        
        for (int i = 1; i <= N; i++) {
            for (int k = 1; k <= K; k++) {
                dp[i][k] = min(dp[i][k], min(f[i - 1][k - 1], g[i - 1][k + 1]) + costs[i - 1][k - 1]);
                
                f[i][k] = min(f[i][k - 1], dp[i][k]);
            }
            
            for (int k = K; k >= 0; k--) {
                g[i][k] = min(g[i][k + 1], dp[i][k]);
            }
        }
        
        int answer = 999999;
        for (int i = 1; i <= K; i++) {
            answer = min(answer, dp[N][i]);
        }
        return answer;
    }
};
