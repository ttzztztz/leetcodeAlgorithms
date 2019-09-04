class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        int dp[nums.size()];
        for (int i = 0; i < nums.size(); i++) {
            dp[i] = 1;
        }

        for (int i = 0; i < nums.size(); i++) {
            int number = nums[i];
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }

        int answer = 0;
        for (int i = 0; i < nums.size(); i++) {
            answer = std::max(answer, dp[i]);
        }
        return answer;
    }
};