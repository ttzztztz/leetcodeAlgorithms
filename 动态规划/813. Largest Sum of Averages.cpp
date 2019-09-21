class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        if (A.size() == 0) {
            return 0.0;
        }

        double dp[A.size() + 1][K + 1];
        int sum[A.size() + 1];

        std::memset(dp, 0, sizeof(dp));
        std::memset(sum, 0, sizeof(sum));
        for (int i = 0; i < A.size(); i++) {
            sum[i + 1] = sum[i] + A[i];
        }

        for (int i = 1; i <= A.size(); i++) {
            dp[i][1] = (sum[i] * 1.0) / (i * 1.0);
        }

        for (int i = 1; i <= A.size(); i++) {
            for (int k = 2; k <= K && k <= i; k++) {
                for (int j = 1; j < i; j++) {
                    dp[i][k] = std::max(
                            dp[i][k],
                            dp[j][k - 1] + (((sum[i] - sum[j]) * 1.0) / ((i - j) * 1.0))
                    );
                }
            }
        }


        return dp[A.size()][K];
    }
};