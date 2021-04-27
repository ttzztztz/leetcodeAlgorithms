class Solution {
public:
    int minInsertions(string s) {
        const int n = s.size();
        vector<vector<int>> f(n, vector<int>(n, 0));
        
        for (int i = 0; i < n; i++) f[i][i] = 1;
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                const int j = i + len - 1;
                
                f[i][j] = 1;
                if (s[i] == s[j]) f[i][j] = f[i + 1][j - 1] + 2;
                f[i][j] = max(f[i][j], max(f[i + 1][j], f[i][j - 1]));
            }
        }
        
        return n - f[0][n - 1];
    }
};