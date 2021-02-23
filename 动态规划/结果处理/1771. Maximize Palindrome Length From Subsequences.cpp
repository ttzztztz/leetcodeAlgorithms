class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        const int n = word1.size(), m = word2.size();
        
        string tmp = word1 + word2;
        vector<vector<int>> f(n + m, vector<int>(n + m, 0));
        for (int i = 0; i < n + m; i++) f[i][i] = 1;
        for (int i = 0; i + 1 < n + m; i++) {
            if (tmp[i] == tmp[i + 1]) f[i][i + 1] = 2;
            else f[i][i + 1] = 1;
        }
        
        for (int len = 3; len <= n + m; len++) {
            for (int i = 0; i + len - 1 < n + m; i++) {
                const int j = i + len - 1;
                
                if (tmp[i] == tmp[j]) f[i][j] = f[i + 1][j - 1] + 2;
                else f[i][j] = max(f[i + 1][j], f[i][j - 1]);
            }
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = n; j < n + m; j++) {
                if (tmp[i] == tmp[j]) ans = max(ans, f[i][j]);
            }
        }
        return ans;
    }
};
