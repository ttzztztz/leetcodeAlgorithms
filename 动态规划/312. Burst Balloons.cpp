class Solution {
public:
    int getCoin(const vector<int>& nums, int index) {
        if (index <= 0 || index > nums.size()) {
            return 1;
        } else {
            return nums[index - 1];
        }
    }
    int maxCoins(vector<int>& nums) {
        if (0 == nums.size()) {
            return 0;
        }

        int dp[nums.size() + 2][nums.size() + 2];
        std::memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= nums.size(); i++) {
            dp[i][i] = getCoin(nums, i - 1) * getCoin(nums, i) * getCoin(nums, i + 1);
        }

        for (int l = 2; l <= nums.size(); l++) {
            for (int i = 1; i + l - 1 <= nums.size(); i++) {
                const int j = i + l - 1;
                for (int k = i; k <= j; k++) {
                    dp[i][j] = std::max(dp[i][j],
                                        dp[i][k - 1] + dp[k + 1][j] + getCoin(nums, i - 1) * getCoin(nums, k) * getCoin(nums, j + 1));
                }
            }
        }

        return dp[1][nums.size()];
    }
};