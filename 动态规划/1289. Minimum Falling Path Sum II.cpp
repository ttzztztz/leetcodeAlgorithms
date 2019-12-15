class Solution {
public:
    int answer = 999999;
    int dfs(vector<vector<int>>& dp, const vector<vector<int>>& arr, int i, int last) {
        if (i >= arr.size()) {
            return 0;
        }

        if (dp[i][last] != -1) {
            return dp[i][last];
        }

        int current = 999999;
        for (int j = 0; j < arr[i].size(); j++) {
            if (j == last) continue;

            current = min(dfs(dp, arr, i + 1, j) + arr[i][j], current);
        }

        return dp[i][last] = current;
    }
    int minFallingPathSum(vector<vector<int>>& arr) {
        const int N = arr.size();

        vector<vector<int>> dp(N + 5, vector<int>(N + 5, -1));
        return dfs(dp, arr, 0, N + 4);
    }
};