class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        const int N = mat.size(), M = mat[0].size();
        vector<vector<int>> prefixSum(N + 1, vector<int>(M + 1, 0)), answer(N, vector<int>(M, 0));
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] + mat[i - 1][j - 1] - prefixSum[i - 1][j - 1];
            }
        }
        
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                const int x = min(i + K, N), y = min(j + K, M);
                const int a = max(1, i - K), b = max(1, j - K);
                
                answer[i - 1][j - 1] = prefixSum[x][y] - prefixSum[a - 1][y] - prefixSum[x][b - 1] + prefixSum[a - 1][b - 1];
            }
        }
        return answer;
    }
};
