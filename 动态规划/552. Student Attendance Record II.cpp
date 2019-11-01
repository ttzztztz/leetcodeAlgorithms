const int MOD = 1000000007;

class Solution {
public:
    int N;
    long long dp[100005][2][3];
    long long dfs(int i, int absent, int continousLate) {
        if (absent > 1 || continousLate > 2) {
            return 0;
        }
        if (i == N) {
            return (absent <= 1 && continousLate <= 2) ? 1 : 0;
        }

        if (dp[i][absent][continousLate] != -1) {
            return dp[i][absent][continousLate];
        }

        long long answer = 0;
        if (absent == 0) {
            answer = (answer + dfs(i + 1, absent + 1, 0)) % MOD;
        }
        answer = (answer + dfs(i + 1, absent, 0)) % MOD;
        if (continousLate <= 1) {
            answer = (answer + dfs(i + 1, absent, continousLate + 1)) % MOD;
        }
        return dp[i][absent][continousLate] = answer % MOD;
    }
    int checkRecord(int n) {
        std::memset(dp, 0xff, sizeof(dp));
        N = n;

        return (int) dfs(0, 0, 0);
    }
};