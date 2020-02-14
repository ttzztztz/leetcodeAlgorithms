class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> &nums) {
        const int N = nums.size();
        
        vector<vector<vector<int>>> f(N + 1, vector<vector<int>>(3, vector<int>(2, -99999999)));
        
        f[0][0][0] = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j <= 2; j++) {
                f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1]);
                
                f[i][j][1] = f[i - 1][j][1] + nums[i - 1];
                if (j >= 1) {
                    f[i][j][1] = max(f[i - 1][j - 1][0] + nums[i - 1], f[i][j][1]);
                    
                    f[i][j][1] = max(f[i - 1][j - 1][1] + nums[i - 1], f[i][j][1]);
                }
            }
        }
        
        return max(f[N][2][0], f[N][2][1]);
    }
};
