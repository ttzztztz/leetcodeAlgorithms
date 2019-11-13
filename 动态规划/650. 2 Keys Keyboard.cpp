class Solution {
public:
    int N;
    int dfs(vector<vector<int>>& dp, int offset, int pasteBin) {
        if (pasteBin >= N || offset > N) {
            return 0x3f3f3f3f;
        }
        if (offset == N) {
            return 0;
        }
        
        if (dp[offset][pasteBin] != 0x3f3f3f3f) {
            return dp[offset][pasteBin];
        }
        
        if (pasteBin == 0) {
            return dp[offset][pasteBin] = dfs(dp, offset, offset) + 1;
        } else if (offset == pasteBin) {
            return dp[offset][pasteBin] = dfs(dp, offset + pasteBin, pasteBin) + 1;
        } else {
            return dp[offset][pasteBin] = min(
                dfs(dp, offset, offset) + 1,
                dfs(dp, offset + pasteBin, pasteBin) + 1
            );
        }
    }
    int minSteps(int n) {
        N = n;
        vector<vector<int>> dp(n + 5, vector<int>(n + 5, 0x3f3f3f3f));
        
        return dfs(dp, 1, 0);
    }
};