class Solution {
public:
    int L, MOD;
    long long dfs(vector<vector<long long>>& dp, int steps, int index) {
        if (index >= L || index < 0) {
            return 0;
        }
        if (steps == 0) {
            return index == 0 ? 1 : 0;
        }
        if (dp[steps][index] != -1) {
            return dp[steps][index];
        }

        long long answer = 0;
        answer = (answer + dfs(dp, steps - 1, index)) % MOD;
        answer = (answer + dfs(dp, steps - 1, index - 1)) % MOD;
        answer = (answer + dfs(dp, steps - 1, index + 1)) % MOD;
        return dp[steps][index] = answer;
    }
    int numWays(int steps, int arrLen) {
        L = arrLen, MOD = 1e9 + 7;

        arrLen = min(arrLen, steps) + 5;

        vector<vector<long long>> dp(steps + 5, vector<long long>(arrLen + 5, -1));

        return dfs(dp, steps, 0) % MOD;
    }
};