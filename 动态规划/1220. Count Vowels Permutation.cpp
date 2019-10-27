const int MOD = 1000000007;

class Solution {
public:
    int N;
    long long dp[20005][6];
    long long dfs(int i, int charIndex) {
        if (i >= N) {
            return 1;
        }
        if (dp[i][charIndex] != -1) {
            return dp[i][charIndex];
        }

        long long currentAnswer = 0;
        if (charIndex == 0) {
            currentAnswer = (currentAnswer + dfs(i + 1, 1)) % MOD;
        } else if (charIndex == 1) {
            currentAnswer = (currentAnswer + dfs(i + 1, 0)) % MOD;
            currentAnswer = (currentAnswer + dfs(i + 1, 2)) % MOD;
        } else if (charIndex == 2) {
            currentAnswer = (currentAnswer + dfs(i + 1, 0)) % MOD;
            currentAnswer = (currentAnswer + dfs(i + 1, 1)) % MOD;
            currentAnswer = (currentAnswer + dfs(i + 1, 3)) % MOD;
            currentAnswer = (currentAnswer + dfs(i + 1, 4)) % MOD;
        } else if (charIndex == 3) {
            currentAnswer = (currentAnswer + dfs(i + 1, 2)) % MOD;
            currentAnswer = (currentAnswer + dfs(i + 1, 4)) % MOD;
        } else {
            currentAnswer = (currentAnswer + dfs(i + 1, 0)) % MOD;
        }
        return dp[i][charIndex] = currentAnswer;
    }
    int countVowelPermutation(int n) {
        this->N = n - 1;
        memset(dp, 0xff, sizeof(dp));

        long long zeroAnswer = 0;
        for (int i = 0; i <= 4; i++) {
            zeroAnswer = (zeroAnswer + dfs(0, i)) % MOD;
        }
        return (int)(zeroAnswer % MOD);
    }
};