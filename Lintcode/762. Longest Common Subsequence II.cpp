class Solution {
public:
    /**
     * @param P: an integer array P
     * @param Q: an integer array Q
     * @param k: the number of allowed changes
     * @return: the length of lca with at most k changes allowed.
     */
    int longestCommonSubsequenceTwo(vector<int> &P, vector<int> &Q, int k) {
        const int N = P.size(), M = Q.size();
        const int K = min(k, max(N, M));
        
        vector<vector<vector<int>>> dp = vector<vector<vector<int>>>(N + 1, vector<vector<int>>(M + 1, vector<int>(K + 1, 0)));
        
        int answer = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                for (int m = 0; m <= K; m++) {
                    if (P[i - 1] == Q[j - 1]) {
                        dp[i][j][m] = dp[i - 1][j - 1][m] + 1;
                    } else {
                        dp[i][j][m] = max(dp[i][j - 1][m], dp[i - 1][j][m]);
                        
                        if (m >= 1) {
                            dp[i][j][m] = max(dp[i][j][m], 1 + dp[i - 1][j - 1][m - 1]);
                        }
                    }
                    
                    answer = max(answer, dp[i][j][m]);
                }
            }
        }
        
        return answer;
    }
};
