class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        int dp[nums.size()];

        for (int i = 0; i < nums.size(); i++) {
            dp[i] = nums[i];
            for (int j = 0; j <= i - 2; j++) {
                dp[i] = std::max(std::max(dp[i], dp[j]), dp[j] + nums[i]);
            }
            if (i >= 1) {
                dp[i] = std::max(dp[i], dp[i - 1]);
            }
        }

        return dp[nums.size() - 1];
    }
};