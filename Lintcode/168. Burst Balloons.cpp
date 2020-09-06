class Solution {
public:
    /**
     * @param nums: A list of integer
     * @return: An integer, maximum coins
     */
    int maxCoins(vector<int> &nums) {
        const int N = nums.size();
        vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
        
        for (int len = 1; len <= N; len++) {
            for (int i = 0; i + len - 1 < N; i++) {
                const int j = i + len - 1;
                
                const int l = i - 1 >= 0 ? nums[i - 1] : 1;
                const int r = j + 1 < N ? nums[j + 1] : 1;
                
                for (int k = i; k <= j; k++) {
                    dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + l * nums[k] * r);
                }
            }
        }
        
        return dp[0][N - 1];
    }
};
