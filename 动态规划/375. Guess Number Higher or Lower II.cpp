class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> f(n + 5, vector<int>(n + 5, 9999999));
        
        for (int i = 1; i <= n; i++) f[i][i] = 0;
        for (int i = 1; i + 1 <= n; i++) f[i][i + 1] = i;
        
        for (int len = 3; len <= n; len++) {
            for (int i = 1; i + len - 1 <= n; i++) {
                const int j = i + len - 1;
                
                for (int k = i + 1; k + 1 <= j; k++) {
                    f[i][j] = min(f[i][j], k + max(f[i][k - 1], f[k + 1][j]));
                }
            }
        }
        
        return f[1][n];
    }
};