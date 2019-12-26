class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<int> dp(N + 5, 0);

        for (int i = 0; i <= N; i++) {
            dp[i] = i;
        }

        for (int k = 2; k <= K; k++) {
            vector<int> dp2(N + 5, 0);

            int x = 1;
            for (int n = 1; n <= N; n++) {
                while (x < n && max(dp[x - 1], dp2[n - x]) > max(dp[x], dp2[n - x - 1])) {
                    x++;
                }

                dp2[n] = 1 + max(dp[x - 1], dp2[n - x]);
            }

            dp = dp2;
        }
        return dp[N];
    }
};