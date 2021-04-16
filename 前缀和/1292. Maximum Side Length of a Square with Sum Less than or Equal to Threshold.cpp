class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        if (mat.empty()) return 0;
        const int n = mat.size(), m = mat[0].size();
        vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }
        
        for (int len = min(n, m); len >= 1; len--) {
            for (int i = 0; i + len <= n; i++) {
                for (int j = 0; j + len <= m; j++) {
                    const int t = f[i + len][j + len] - f[i][j + len] - f[i + len][j] + f[i][j];
                    if (t <= threshold) return len;
                }
            }
        }
        return 0;
    }
};