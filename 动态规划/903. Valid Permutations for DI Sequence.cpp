const int MOD = 1000000007;

class Solution {
public:
    int numPermsDISequence(string S) {
        const int N = S.size();
        long long dp[N + 1][N + 1];
        std::memset(dp, 0, sizeof(dp));

        for (int i = 0; i <= N; i++) {
            dp[0][i] = 1;
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 0; j <= i; j++) {
                if (S[i - 1] == 'I') {
                    for (int k = j; k < i; k++) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
                    }
                } else { // D
                    for (int k = 0; k < j; k++) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
                    }
                }
            }
        }

        long long answer = 0;
        for (int i = 0; i <= N; i++) {
            answer = (answer + dp[N][i]) % MOD;
        }
        return (int) answer;
    }
};