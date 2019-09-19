class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int dp[nums.size() + 1];
        std::memset(dp, 0, sizeof(dp));

        dp[0] = nums[0];
        int answer = dp[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = std::max(dp[i - 1] + nums[i], nums[i]);
            answer = std::max(answer, dp[i]);
        }

        return answer;
    }
};