class Solution {
public:
    int change(const string& s, int i, int j) {
        int answer = 0;
        while (i < j) {
            if (s[i] != s[j]) {
                answer++;
            }
            i++, j--;
        }
        return answer;
    }
    int dfs(const string& s, vector<vector<int>>& dp, vector<vector<int>>& chg, int index, int k) {
        if (index == s.size()) {
            if (k == 0) {
                return 0;
            } else {
                return 9999999;
            }
        }
        if (k == 0) {
            if (index == s.size()) {
                return 0;
            } else {
                return 9999999;
            }
        }
        if (dp[index][k] != -1) {
            return dp[index][k];
        }

        int answer = 99999999;
        for (int i = index; i < s.size(); i++) {
            const int cost = chg[index][i];
            answer = min(answer, cost + dfs(s, dp, chg, i + 1, k - 1));
        }
        return dp[index][k] = answer;
    }
    int palindromePartition(string s, int k) {
        vector<vector<int>> chg(s.size() + 5, vector<int>(s.size() + 5, 999999));
        vector<vector<int>> dp(105, vector<int>(105, -1));
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                chg[i][j] = change(s, i, j);
            }
        }

        return dfs(s, dp, chg, 0, k);
    }
};