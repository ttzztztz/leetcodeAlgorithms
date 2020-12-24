class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        int ans = 0;
        if (M.empty()) return 0;
        const int n = M.size(), m = M[0].size();
        
        vector<vector<int>> f(n + 2, vector<int>(m + 2, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                const int val = M[i - 1][j - 1];
                if (val == 1) {
                    f[i][j] = f[i][j - 1] + 1;
                    ans = max(ans, f[i][j]);
                }
            }
        }
        
        f = vector<vector<int>>(n + 2, vector<int>(m + 2, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                const int val = M[i - 1][j - 1];
                if (val == 1) {
                    f[i][j] = f[i - 1][j] + 1;
                    ans = max(ans, f[i][j]);
                }
            }
        }
        
        f = vector<vector<int>>(n + 2, vector<int>(m + 2, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                const int val = M[i - 1][j - 1];
                if (val == 1) {
                    f[i][j] = f[i - 1][j - 1] + 1;
                    ans = max(ans, f[i][j]);
                }
            }
        }
        
        f = vector<vector<int>>(n + 2, vector<int>(m + 2, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                const int val = M[i - 1][j - 1];
                if (val == 1) {
                    f[i][j] = f[i - 1][j + 1] + 1;
                    ans = max(ans, f[i][j]);
                }
            }
        }
        return ans;
    }
};
