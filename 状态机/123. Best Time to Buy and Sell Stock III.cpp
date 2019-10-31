class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int N = prices.size();
        int dp[N + 1][3][2];
        std::memset(dp, 0, sizeof(dp));

        for (int i = 0; i <= N; i++) {
            dp[i][0][1] = -99999999;
        }
        for (int k = 0; k <= 2; k++) {
            dp[0][k][1] = -99999999;
        }

        for (int i = 1; i <= N; i++) {
            const int price = prices[i - 1];

            for (int k = 1; k <= 2; k++) {
                dp[i][k][0] = std::max(
                        dp[i - 1][k][0],
                        dp[i - 1][k][1] + price
                );

                dp[i][k][1] = std::max(
                        dp[i - 1][k][1],
                        dp[i - 1][k - 1][0] - price
                );
            }
        }

        return dp[N][2][0];
    }
};