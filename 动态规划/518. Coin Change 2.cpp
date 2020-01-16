class Solution {
public:
    int change(int amount, vector<int>& coins) {
        const int N = coins.size();
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        
        for (int i = 0; i < N; i++) {
            for (int j = coins[i]; j <= amount; j++) {
                dp[j] += dp[j - coins[i]];
            }
        }
        
        return dp[amount];
    }
};
