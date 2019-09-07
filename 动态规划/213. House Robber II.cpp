class Solution {
public:
    int robSub(vector<int>& nums, int start, int end) {
        if (end - start + 1 <= 2) {
            int answer = 0;
            for (int i = start; i <= end; i++) {
                answer = std::max(answer, nums[i]);
            }
            return answer;
        }

        int dp[end - start + 1];
        std::memset(dp, 0, sizeof(dp));
        dp[0] = nums[start];
        dp[1] = std::max(nums[start + 1], nums[start]);
        dp[2] = std::max(dp[1], dp[0] + nums[start + 2]);

        for (int i = 3; i <= end - start; i++) {
            dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[start + i]);
        }

        return dp[end - start];
    }

    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        if (nums.size() == 1) {
            return nums[0];
        }

        return std::max(robSub(nums, 0, nums.size() - 2), robSub(nums, 1, nums.size() - 1));
    }
};