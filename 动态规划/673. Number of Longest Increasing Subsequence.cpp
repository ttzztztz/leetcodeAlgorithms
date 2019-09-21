class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        } else if (nums.size() == 1) {
            return 1;
        }

        int dp[nums.size() + 1], count[nums.size() + 1];
        for (int i = 0; i <= nums.size(); i++) {
            dp[i] = 1;
            count[i] = 1;
        }

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] > nums[i]) {
                    if (dp[j] < dp[i] + 1) {
                        dp[j] = dp[i] + 1;
                        count[j] = count[i];
                    } else if (dp[j] == dp[i] + 1) {
                        count[j] += count[i];
                    }
                }
            }
        }

        int answer = 0, maxLength = 1 << 32 - 1;
        for (int i = 0; i < nums.size(); i++) {
            maxLength = std::max(maxLength, dp[i]);
        }

        for (int i = 0; i < nums.size(); i++) {
            if (maxLength == dp[i]) {
                answer += count[i];
            }
        }
        return answer;
    }
};