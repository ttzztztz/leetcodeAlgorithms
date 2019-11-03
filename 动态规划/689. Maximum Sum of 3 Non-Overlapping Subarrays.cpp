class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        const int N = nums.size();
        vector<int> prefixSum;
        prefixSum.push_back(0);
        for (int i = 1; i <= nums.size(); i++) {
            prefixSum.push_back(prefixSum[i - 1] + nums[i - 1]);
        }

        vector<vector<int>> dp(5, vector<int>(N + 10, -99999));
        for (int i = k; i <= N; i++) {
            dp[0][i] = 0;
        }

        for (int i = 1; i <= 3; i++) {
            for (int j = N - k; j >= 0; j--) {
                const int sum = prefixSum[j + k] - prefixSum[j];

                dp[i][j] = std::max(dp[i][j + 1], dp[i - 1][j + k] + sum);
            }
        }
        vector<int> answer;
        int i = 3, j = 0;
        while (i >= 1 && j <= N - k) {
            const int sum = prefixSum[j + k] - prefixSum[j];
            if (dp[i][j] <= dp[i - 1][j + k] + sum) {
                answer.push_back(j);
                j += k;
                i--;
            } else {
                j++;
            }
        }
        return answer;
    }
};