const int MOD = 1000000007;

class Solution {
public:
    int numMusicPlaylists(int N, int L, int K) {
        long long dp[N + 5][L + 5];
        std::memset(dp, 0, sizeof(dp));

        dp[0][0] = 1;

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= L; j++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] * (N - i + 1) % MOD) % MOD;
                dp[i][j] = (dp[i][j] + dp[i][j - 1] * std::max(0, i - K) % MOD) % MOD;
            }
        }

        return dp[N][L];
    }
};