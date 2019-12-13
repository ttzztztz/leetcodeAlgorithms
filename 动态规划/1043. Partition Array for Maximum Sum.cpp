class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        const int N = A.size();
        vector<int> dp(N + 5, -1);

        dp[0] = 0;
        for (int i = 0; i < N; i++) {
            int number = A[i];
            for (int k = 0; k < K && i + k < N; k++) {
                number = max(number, A[i + k]);

                if (i - 1 >= 0) {
                    dp[i + k] = max(dp[i + k], dp[i - 1] + (k + 1) * number);
                } else {
                    dp[i + k] = max(dp[i + k], (k + 1) * number);
                }
            }
        }

        return dp[N - 1];
    }
};