class Solution {
public:
    int numWays(int steps, int arrLen) {
        const int MOD = 1e9 + 7;
        if (arrLen > steps) {
            arrLen = min(steps, arrLen) + 5;
        }

        vector<long long> dp(arrLen + 5, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= steps; i++) {
            vector<long long> cur(arrLen + 5, 0);

            for (int j = 0; j <= min(arrLen - 1, steps - i); j++) {
                cur[j] = dp[j];

                if (j - 1 >= 0) {
                    cur[j] = (cur[j] + dp[j - 1]) % MOD;
                }
                if (j + 1 <= arrLen) {
                    cur[j] = (cur[j] + dp[j + 1]) % MOD;
                }
            }

            dp = cur;
        }

        return dp[0];
    }
};