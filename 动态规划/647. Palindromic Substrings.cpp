class Solution {
public:
    bool dfs(vector<vector<int>>& dp, const string& s, int i, int j) {
        if (i >= j) {
            return true;
        }

        if (dp[i][j] != -1) {
            return dp[i][j] == 1;
        }

        if (s[i] == s[j]) {
            return dp[i][j] = dfs(dp, s, i + 1, j - 1);
        } else {
            return dp[i][j] = false;
        }
    }
    int countSubstrings(string s) {
        const int N = s.size();
        vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));

        int answer = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j++) {
                if (dfs(dp, s, i, j)) {
                    answer++;
                }
            }
        }

        return answer;
    }
};