class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int dp[10005];
        std::memset(dp, 0, sizeof(dp));

        for (int number : nums) {
            dp[number]++;
        }

        for (int i = 2; i <= 10000; i++) {
            dp[i] = std::max(dp[i - 1], dp[i - 2] + i * dp[i]);
        }

        return dp[10000];
    }
};