class Solution {
public:
    /**
     * @param nums: an array
     * @param k: an integer
     * @return: three non-overlapping subarrays with maximum sum
     */
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k) {
        const int N = nums.size();
        vector<vector<int>> dp(N + 1, vector<int>(4, 0));
        
        vector<int> f(N + 1, 0);
        for (int i = 1; i <= N; i++) f[i] = f[i - 1] + nums[i - 1];
        
        for (int j = 1; j <= 3; j++) {
            for (int i = 1; i <= N; i++) {
                dp[i][j] = dp[i - 1][j];
                if (i >= k) {
                    dp[i][j] = max(dp[i][j], dp[i - k][j - 1] + f[i] - f[i - k]);
                }
            }
        }
        
        vector<int> answer;
        int i = N, j = 3;
        while (i >= 1 && j >= 1) {
            if (dp[i][j] == dp[i - 1][j]) i--;
            else {
                answer.push_back(i - k);
                i -= k;
                j--;
            }
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};
