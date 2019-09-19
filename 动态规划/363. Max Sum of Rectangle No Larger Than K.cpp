class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.size() == 0) {
            return 0;
        }
        // multiset<int> set;
        int dp[matrix.size() + 1][matrix[0].size() + 1];
        std::memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= matrix[0].size(); i++) {
            dp[1][i] = dp[1][i - 1] + matrix[0][i - 1];
        }
        for (int i = 1; i <= matrix.size(); i++) {
            dp[i][1] = dp[i - 1][1] + matrix[i - 1][0];
        }
        for (int i = 1; i <= matrix.size(); i++) {
            for (int j = 1; j <= matrix[0].size(); j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + matrix[i - 1][j - 1];
                // set.insert(dp[i][j]);
            }
        }

        int answer = 1 << 32 - 1;
        for (int i = 1; i <= matrix.size(); i++) {
            for (int j = 1; j <= matrix[0].size(); j++) {
                for (int n = 1; n <= i; n++) {
                    for (int m = 1; m <= j; m++) {
                        int query = dp[i][j] - dp[n - 1][j] - dp[i][m - 1] + dp[n - 1][m - 1];
                        if (query <= k) {
                            answer = std::max(answer, query);
                        }
                    }
                }
            }
        }
        return answer;
    }
};