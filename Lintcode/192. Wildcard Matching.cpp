class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "?" and "*"
     * @return: is Match?
     */
    bool isMatch(string &s, string &p) {
        N = s.size(), M = p.size();
        dp = vector<vector<int>>(N + 5, vector<int>(M + 5, -1));
        return dfs(s, p, 0, 0);
    }
private:
    vector<vector<int>> dp;
    int N, M;
    int dfs(const string &s, const string &p, int i, int j) {
        if (j >= M) return i >= N;
        if (dp[i][j] != -1) return dp[i][j];
        
        int answer = 0;
        if (i < N && (s[i] == p[j] || p[j] == '?')) {
            answer |= dfs(s, p, i + 1, j + 1);
        }
        if (p[j] == '*') {
            if (i < N) {
                answer |= dfs(s, p, i + 1, j);
            }
            answer |= dfs(s, p, i, j + 1);
        }
        return dp[i][j] = answer;
    }
};
