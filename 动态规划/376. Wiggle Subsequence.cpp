class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        const int N = nums.size();
        int answer = 0;
        
        vector<vector<int>> dp(N, vector<int>(2, 1));
        for (int i = 0; i < N; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    dp[i][0] = max(dp[i][0], dp[j][1] + 1);
                } else if (nums[i] < nums[j]) {
                    dp[i][1] = max(dp[i][1], dp[j][0] + 1);
                }
            }
            answer = max(answer, max(dp[i][0], dp[i][1]));
        }
        
        return answer;
    }
};
