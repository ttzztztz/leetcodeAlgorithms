class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& g) {
        const int N = g.size(), M = g[0].size();
        vector<vector<int>> f(N + 1, vector<int>(M + 1, 99999999));
        
        f[N][M - 1] = 1, f[N - 1][M] = 1;
        for (int i = N - 1; i >= 0; i--) {
            for (int j = M - 1; j >= 0; j--) {
                f[i][j] = max(min(f[i + 1][j], f[i][j + 1]) - g[i][j], 1);
            }
        }
        
        return f[0][0];
    }
};
