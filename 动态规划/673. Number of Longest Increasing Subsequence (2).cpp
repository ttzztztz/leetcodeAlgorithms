class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }

        const int N = nums.size();
        vector<int> dp(N, 1), count(N, 1);

        int maxLen = 1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    } else if (dp[i] == dp[j] + 1) {
                        count[i] += count[j];
                    }

                    maxLen = max(maxLen, dp[i]);
                }
            }
        }

        int answer = 0;
        for (int i = 0; i < N; i++) {
            if(dp[i] == maxLen) {
                answer += count[i];
            }
        }
        return answer;
    }
};