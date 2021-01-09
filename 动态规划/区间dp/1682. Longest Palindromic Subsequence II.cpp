class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int ans = 0;
        const int n = s.size();
        
        int f[255][255][27];
        memset(f, 0, sizeof f);
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                const int j = i + len - 1;
                
                if (s[i] == s[j]) {
                    const int c = s[i] - 'a';
                    for (int k = 0; k < 26; k++) {
                        if (c == k) continue;
                        
                        f[i][j][c] = max(f[i][j][c], f[i + 1][j - 1][k] + 2);
                        ans = max(ans, f[i][j][c]);
                    }
                }
                
                for (int k = 0; k < 26; k++) {
                    f[i][j][k] = max(f[i][j][k], max(f[i + 1][j][k], f[i][j - 1][k]));
                    ans = max(ans, f[i][j][k]);
                }
            }
        }
        
        return ans;
    }
};
