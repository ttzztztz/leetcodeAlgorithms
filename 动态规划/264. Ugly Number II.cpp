class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 0) {
            return 0;
        }

        int dp[n + 1];
        std::memset(dp, 0, sizeof(dp));

        dp[0] = 1;
        int ptr2 = 0, ptr3 = 0, ptr5 = 0;
        for (int i = 1; i < n; i++) {
            dp[i] = std::min(std::min(dp[ptr2] * 2, dp[ptr3] * 3), dp[ptr5] * 5);

            if (dp[ptr2] * 2 == dp[i]) {
                ptr2++;
            }
            if (dp[ptr3] * 3 == dp[i]) {
                ptr3++;
            }
            if (dp[ptr5] * 5 == dp[i]) {
                ptr5++;
            }

        }

        return dp[n - 1];
    }
};