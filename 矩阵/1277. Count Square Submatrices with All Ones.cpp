class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        const int n = matrix.size(), m = matrix[0].size();
        int ans = 0;
        vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (matrix[i - 1][j - 1] == 0) continue;
                f[i][j] = min(min(f[i][j - 1], f[i - 1][j]), f[i - 1][j - 1]) + 1;
                ans += f[i][j];
            }
        }
        return ans;
    }
};
