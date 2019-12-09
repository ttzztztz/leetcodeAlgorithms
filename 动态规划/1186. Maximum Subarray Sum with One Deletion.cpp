class Solution {
public:
    int maximumSum(vector<int>& arr) {
        const int N = arr.size();

        int answer = -99999;
        vector<vector<int>> dp(N + 5, vector<int>(2, -99999));
        dp[0][0] = answer = arr[0];

        for (int i = 1; i < N; i++) {
            dp[i][0] = arr[i];

            for (int j = 0; j <= 1; j++) {
                // select
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + arr[i]);

                if (j - 1 >= 0) {
                    // not select
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
                }

                answer = max(dp[i][j], answer);
            }
        }

        return answer;
    }
};