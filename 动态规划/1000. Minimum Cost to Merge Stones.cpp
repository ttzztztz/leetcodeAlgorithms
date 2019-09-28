class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        if (0 != (stones.size() - K) % (K - 1)) {
            return -1;
        }

        int sum[35], dp[35][35][35];
        std::memset(sum, 0, sizeof(sum));
        std::memset(dp, 0x2f, sizeof(dp));

        for (int i = 1; i <= stones.size(); i++) {
            sum[i] = sum[i - 1] + stones[i - 1];
        }

        for (int i = 1; i <= stones.size(); i++) {
            dp[i][i][1] = 0;
        }

        for (int l = 2; l <= stones.size(); l++) {
            for (int i = 1; i + l - 1 <= stones.size(); i++) {
                int j = i + l - 1;
                for (int n = i; n + 1 <= j; n++) {
                    for (int m = 2; m <= K; m++) {
                        dp[i][j][m] = std::min(dp[i][j][m], dp[i][n][1] + dp[n + 1][j][m - 1]);
                    }
                }
                dp[i][j][1] = dp[i][j][K] + sum[j] - sum[i - 1];
            }
        }

        return dp[1][stones.size()][1];
    }
};