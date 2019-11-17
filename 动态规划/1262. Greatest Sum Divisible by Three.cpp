class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        const int N = nums.size();
        long long dp[40005][5];
        memset(dp, 0xff, sizeof(dp));

        dp[0][1] = dp[0][2] = -999999;
        dp[0][0] = 0;

        for (int i = 0; i < N; i++) {
            const int number = nums[i];

            for (int j = 0; j <= 2; j++) {
                if (dp[i][j] < 0) {
                    continue;
                }
                // no select
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);

                // select
                dp[i + 1][(j + number) % 3] = max(dp[i + 1][(j + number) % 3], dp[i][j] + number);
            }
        }

        return dp[N][0];
    }
};