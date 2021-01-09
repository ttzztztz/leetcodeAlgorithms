class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        const int n = s.size();
        return n - lps(s) <= k;
    }
private:
    int lps(const string& s) {
        const int n = s.size();
        vector<vector<int>> f(n + 2, vector<int>(n + 2, 0));
        for (int i = 0; i < n; i++) f[i][i] = 1;
        
        int ans = 1;
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                const int j = i + len - 1;
                if (s[i] == s[j]) {
                    f[i][j] = f[i + 1][j - 1] + 2;
                } else {
                    f[i][j] = max(f[i][j - 1], f[i + 1][j]);
                }
                ans = max(ans, f[i][j]);
            }
        }
        return ans;
    }
};
