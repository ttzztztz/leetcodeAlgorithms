class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: An integer denote to find k non-overlapping subarrays
     * @return: An integer denote the sum of max k non-overlapping subarrays
     */
    int maxSubArray(vector<int> &nums, int k) {
        const int N = nums.size();
        
        vector<vector<vector<int>>> f(N + 1, vector<vector<int>>(k + 1, vector<int>(2, -99999999)));
        
        f[0][0][0] = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j <= k; j++) {
                f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1]);
                
                f[i][j][1] = f[i - 1][j][1] + nums[i - 1];
                if (j >= 1) {
                    f[i][j][1] = max(f[i - 1][j - 1][0] + nums[i - 1], f[i][j][1]);
                    
                    f[i][j][1] = max(f[i - 1][j - 1][1] + nums[i - 1], f[i][j][1]);
                }
            }
        }
        
        return max(f[N][k][0], f[N][k][1]);
    }
};
