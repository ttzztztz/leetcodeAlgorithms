class Solution {
public:
    int countSubstrings(string s, string t) {
        int ans = 0;
        const int n = s.size(), m = t.size();
        
        vector<vector<int>> f(n + 2, vector<int>(m + 2, 0)), g(n + 2, vector<int>(m + 2, 0));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) f[i][j] = f[i - 1][j - 1] + 1;
            }
        }
        
        for (int i = n; i >= 1; i--) {
            for (int j = m; j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) g[i][j] = g[i + 1][j + 1] + 1;
            }
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) continue;
                ans += (f[i - 1][j - 1] + 1) * (g[i + 1][j + 1] + 1);
            }
        }
        
        return ans;
    }
};
