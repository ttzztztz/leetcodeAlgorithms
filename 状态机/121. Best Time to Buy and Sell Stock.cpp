class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int N = prices.size();
        int dp[N + 1][2][2];
        std::memset(dp, 0, sizeof(dp));

        for (int i = 0; i <= N; i++) {
            dp[i][0][1] = -999999;
        }
        dp[0][1][1] = -999999;

        for (int i = 1; i <= N; i++) {
            const int price = prices[i - 1];

            dp[i][1][0] = std::max(
                    dp[i - 1][1][0],
                    dp[i - 1][1][1] + price
            );

            dp[i][1][1] = std::max(
                    dp[i - 1][1][1],
                    dp[i - 1][0][0] - price
            );
        }

        return dp[N][1][0];
    }
};