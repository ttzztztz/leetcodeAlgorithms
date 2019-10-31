class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int N = prices.size();

        int dp[N + 1][2];
        memset(dp, 0, sizeof(dp));

        dp[0][1] = -9999999;

        for (int i = 1; i <= N; i++) {
            const int price = prices[i - 1];

            dp[i][0] = std::max(
                    dp[i - 1][0],
                    dp[i - 1][1] + price
            );

            if (i >= 2) {
                dp[i][1] = std::max(
                        dp[i - 1][1],
                        dp[i - 2][0] - price
                );
            } else {
                dp[i][1] = std::max(
                        dp[i - 1][1],
                        dp[i - 1][0] - price
                );
            }
        }

        return dp[N][0];
    }
};