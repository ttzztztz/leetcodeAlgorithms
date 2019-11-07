const int MOD = 1000000007;

class Solution {
public:
    int countPalindromicSubsequences(string S) {
        vector<vector<int>> dp(1005, vector<int>(1005, -1));
        const int N = S.size();

        return dfs(S, dp, 0, N - 1);
    }
    int dfs(const string& S, vector<vector<int>>& dp, int start, int end) {
        if (start == end) {
            return 1;
        }
        if (end < start) {
            return 0;
        }
        if (dp[start][end] != -1) {
            return dp[start][end];
        }

        if (S[start] == S[end]) {
            int leftPtr = start + 1, rightPtr = end - 1;
            const int ch = S[start];
            while (leftPtr <= rightPtr && S[leftPtr] != ch) {
                leftPtr++;
            }
            while (leftPtr <= rightPtr && S[rightPtr] != ch) {
                rightPtr--;
            }

            if (leftPtr > rightPtr) {
                return dp[start][end] = (2 * dfs(S, dp, start + 1, end - 1) % MOD + 2) % MOD;
            } else if (leftPtr == rightPtr) {
                return dp[start][end] = (2 * dfs(S, dp, start + 1, end - 1) % MOD + 1) % MOD;
            } else {
                return dp[start][end] = (2 * dfs(S, dp, start + 1, end - 1) % MOD - dfs(S, dp, leftPtr + 1, rightPtr - 1) + MOD) % MOD;
            }

        } else {
            return dp[start][end] = (
                                            ((dfs(S, dp, start + 1, end) + dfs(S, dp, start, end - 1)) % MOD)
                                            + MOD - dfs(S, dp, start + 1, end - 1)
                                    ) % MOD;
        }

    }
};