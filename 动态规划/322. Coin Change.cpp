class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount + 1];
        std::memset(dp, 0x7f, sizeof(dp));

        dp[0] = 0;
        for (int number : coins) {
            for (int i = number; i <= amount; i++) {
                dp[i] = std::min(dp[i], dp[i - number] + 1);
            }
        }

        return dp[amount] != 0x7f7f7f7f ? dp[amount] : -1;
    }
};