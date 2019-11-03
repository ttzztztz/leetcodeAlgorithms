class Solution {
public:
    int minimumMoves(vector<int>& arr) {
        const int N = arr.size();
        int dp[N + 5][N + 5];
        memset(dp, 0x5f, sizeof(dp));

        for (int i = 0; i < N; i++) {
            dp[i][i] = 1;
        }
        for (int i = 0; i < N - 1; i++) {
            if (arr[i] == arr[i + 1]) {
                dp[i][i + 1] = 1;
            } else {
                dp[i][i + 1] = 2;
            }
        }

        for (int len = 3; len <= N; len++) {
            for (int i = 0; i + len - 1 < N; i++) {
                const int j = i + len - 1;
                if (arr[i] == arr[j]) {
                    dp[i][j] = dp[i + 1][j - 1];
                }

                for (int k = i; k + 1 <= j; k++) {
                    dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                }
            }
        }
        return dp[0][N - 1];
    }
};