class Solution {
public:
    string encode(string s) {
        const int n = s.size();
        vector<vector<string>> dp(n + 1, vector<string>(n + 1));
        
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                const int j = i + len - 1;
                dp[i][j] = Compress(s.substr(i, len));
                for (int k = i; k + 1 <= j; k++) {
                    if (Compress(dp[i][k] + dp[k + 1][j]).size() < dp[i][j].size()) {
                        dp[i][j] = Compress(dp[i][k] + dp[k + 1][j]);
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
private:
    string Compress(const string& str) {
        string new_str = str + str;
        const int idx = new_str.find(str, 1);
        const int len = idx;
        string compressed = to_string(str.size() / len) + "[" + str.substr(0, len) + "]";
        
        if (compressed.size() < str.size()) return compressed;
        else return str;
    }
};
