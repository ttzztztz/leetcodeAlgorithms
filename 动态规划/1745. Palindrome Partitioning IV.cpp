class Solution {
public:
    bool checkPartitioning(string s) {
        const int n = s.size();
        vector<vector<bool>> f(n + 1, vector<bool>(n + 1, false));
        for (int i = 0; i < n; i++) f[i][i] = true;
        for (int i = 0; i + 1 < n; i++) {
            if (s[i] == s[i + 1]) f[i][i + 1] = true;
        }
        
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                const int j = i + len - 1;
                if (s[i] == s[j]) f[i][j] = f[i + 1][j - 1];
                else f[i][j] = false;
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j + 1 < n; j++) {
                if (f[0][i] && f[i + 1][j] && f[j + 1][n - 1]) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
