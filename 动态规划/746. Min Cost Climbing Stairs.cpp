class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int dp[cost.size() + 2];
        std::memset(dp, 0x7f, sizeof(dp));
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 0; i < cost.size(); i++) {
            int nowCost = cost[i];

            dp[i + 2] = std::min(dp[i + 1], dp[i]) + nowCost;
        }
        return std::min(dp[cost.size() + 1], dp[cost.size()]);
    }
};