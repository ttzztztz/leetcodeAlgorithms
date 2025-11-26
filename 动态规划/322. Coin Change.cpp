class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, numeric_limits<int>::max());
        
        dp[0] = 0;
        for (long long i = 0; i <= amount; i++) {
            for (long long j : coins) {
                if (i - j >= 0 && dp[i - j] != numeric_limits<int>::max()) {
                    dp[i] = min(dp[i], dp[i - j] + 1);
                }
            }
        }

        if (dp[amount] == numeric_limits<int>::max()) {
            return -1;
        }
        return dp[amount];
    }
};