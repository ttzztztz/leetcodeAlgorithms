class Solution {
public:
    /**
     * @param s: a string
     * @return: return a string
     */
    string encode(string &s) {
        const int N = s.size();
        vector<vector<string>> dp(N + 1, vector<string>(N + 1));
        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j++) {
                dp[i][j] = s.substr(i, j - i + 1);
            }
        }
        
        for (int len = 2; len <= N; len++) {
            for (int i = 0; i + len - 1 < N; i++) {
                const int j = i + len - 1;
                
                for (int k = i; k + 1 <= j; k++) {
                    if (dp[i][k].size() + dp[k + 1][j].size() < dp[i][j].size()) {
                        dp[i][j] = dp[i][k] + dp[k + 1][j];
                    }
                }
                
                const string temp = s.substr(i, len);
                const int index = (temp + temp).find(temp, 1);
                if (index < temp.size()) {
                    const int repeat = temp.size() / index;
                    const string next = to_string(repeat) + '[' + dp[i][i + index - 1] + ']';
                    if (next.size() < dp[i][j].size()) {
                        dp[i][j] = next;
                    }
                }
            }
        }
        
        return dp[0][N - 1];
    }
};
