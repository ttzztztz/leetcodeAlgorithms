class Solution {
public:
    int maxProfitInfinity(vector<int>& prices) {
        const int N = prices.size();
        int dp[N + 1][2];
        std::memset(dp, 0, sizeof(dp));

        dp[0][1] = -99999999;

        for (int i = 1; i <= N; i++) {
            const int price = prices[i - 1];
            dp[i][0] = std::max(
                    dp[i - 1][0],
                    dp[i - 1][1] + price
            );

            dp[i][1] = std::max(
                    dp[i - 1][1],
                    dp[i - 1][0] - price
            );
        }

        return dp[N][0];
    }

    int maxProfit(int k, vector<int>& prices) {
        const int N = prices.size();

        if (k > N / 2) {
            return maxProfitInfinity(prices);
        }

        int dp[N + 1][k + 1][2];
        std::memset(dp, 0, sizeof(dp));

        for (int i = 0; i <= N; i++) {
            dp[i][0][1] = -999999;
        }
        for (int j = 0; j <= k; j++) {
            dp[0][j][1] = -999999;
        }

        for (int i = 1; i <= N; i++) {
            const int price = prices[i - 1];
            for (int j = 1; j <= k; j++) {
                dp[i][j][0] = std::max(
                        dp[i - 1][j][0],
                        dp[i - 1][j][1] + price
                );

                dp[i][j][1] = std::max(
                        dp[i - 1][j][1],
                        dp[i - 1][j - 1][0] - price
                );
            }
        }

        return dp[N][k][0];
    }
};