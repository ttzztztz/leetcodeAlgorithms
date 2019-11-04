class Solution {
public:
    int distinctSubseqII(string S) {
        const int N = S.size();
        const int MOD = 1000000007;

        vector<long long> dp(N + 5, 0);
        vector<int> last(26, -1);
        dp[0] = 1;
        for (int i = 1; i <= N; i++) {
            const int ch = S[i - 1] - 'a';

            if (last[ch] == -1) {
                dp[i] = (dp[i - 1] * 2 % MOD) % MOD;
            } else {
                dp[i] = ((dp[i - 1] * 2 % MOD) - dp[last[ch] - 1]) % MOD;
            }

            if (dp[i] < 0) {
                dp[i] += MOD;
            }
            last[ch] = i;
        }

        return dp[N] - 1;
    }
};