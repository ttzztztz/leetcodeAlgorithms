class Solution {
public:
    int dp[105][105];
    int N;
    string str;
    int dfs(int i, int j) {
        if (i > j) {
            return 0;
        }
        if (i == j) {
            return 1;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int answer = 1 + dfs(i + 1, j);
        for (int k = i + 1; k <= j; k++) {
            if (str[i] == str[k]) {
                answer = std::min(dfs(i + 1, k) + dfs(k + 1, j), answer);
            }
        }
        return dp[i][j] = answer;
    }
    int strangePrinter(string s) {
        N = s.size();
        str = s;
        memset(dp, 0xff, sizeof(dp));

        return dfs(0, N - 1);
    }
};