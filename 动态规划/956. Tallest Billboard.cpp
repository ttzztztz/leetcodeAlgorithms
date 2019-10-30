class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        const int N = rods.size();
        vector<vector<int>> dp(25, vector<int>(5005, -1));
        dp[0][0] = 0;

        for (int i = 1; i <= N; i++) {
            const int h = rods[i - 1];

            for (int j = 0; j <= 5000; j++) {
                if (dp[i - 1][j] < 0) {
                    continue;
                }

                dp[i][j] = std::max(dp[i][j], dp[i - 1][j]);

                if (j + h <= 5000) {
                    dp[i][j + h] = std::max(dp[i][j + h], dp[i - 1][j]);
                }

                if (abs(j - h) <= 5000) {
                    dp[i][abs(j - h)] = std::max(dp[i][abs(j - h)], dp[i - 1][j] + std::min(j, h));
                }

            }
        }

        return dp[N][0];
    }
};