class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;

        const int n = s.size();
        vector<vector<int>> f(n, vector<int>(n, 0));
        
        for (int i = 0; i < n; i++) f[i][i] = 1, ans++;
        for (int i = 0; i + 1 < n; i++) {
            if (s[i] == s[i + 1]) f[i][i + 1] = 1, ans++;
        }
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                const int j = i + len - 1;
                
                if (s[i] == s[j]) {
                    f[i][j] |= f[i + 1][j - 1];
                }
                
                if (f[i][j]) ans++;
            }
        }
        return ans;
    }
};
