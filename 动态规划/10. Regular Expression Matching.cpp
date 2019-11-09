class Solution {
public:
    int S, P;
    bool isMatch(string s, string p) {
        S = s.size(), P = p.size();

        vector<vector<int>> dp(S + 5, vector<int>(P + 5, -1));
        return dfs(s, p, dp, 0, 0);
    }
    bool dfs(const string& s, const string& p, vector<vector<int>>& dp, int i, int j) {
        if (j >= P) {
            return i == S;
        }

        if (dp[i][j] != -1) {
            return dp[i][j] == 1;
        }

        bool match = i < S && (p[j] == s[i] || p[j] == '.');
        if (j + 1 < P && p[j + 1] == '*') {
            return dp[i][j] = dfs(s, p, dp, i, j + 2) || (match && dfs(s, p, dp, i + 1, j));
        } else {
            return dp[i][j] = match && dfs(s, p, dp, i + 1, j + 1);
        }
    }
};