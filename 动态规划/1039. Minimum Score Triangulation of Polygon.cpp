class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
        const int N = A.size();
        vector<vector<int>> f(N, vector<int>(N, 0));
        
        for (int len = 3; len <= N; len++) {
            for (int i = 0; i + len - 1 < N; i++) {
                const int j = i + len - 1;
                f[i][j] = numeric_limits<int>::max();
                for (int k = i + 1; k < j; k++) {
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j] + A[i] * A[k] * A[j]);
                }
            }
        }
        
        return f[0][N - 1];
    }
};
