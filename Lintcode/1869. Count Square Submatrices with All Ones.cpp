class Solution {
public:
    /**
     * @param matrix: a matrix
     * @return: return how many square submatrices have all ones
     */
    int countSquares(vector<vector<int>> &matrix) {
        const int N = matrix.size(), M = matrix[0].size();
        vector<vector<int>> f(N + 1, vector<int>(M + 1, 0));
        int answer = 0;
        
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (matrix[i - 1][j - 1] == 0) continue;
                
                f[i][j] = min(f[i - 1][j], min(f[i - 1][j - 1], f[i][j - 1])) + 1;
                
                answer += f[i][j];
            }
        }
        
        return answer;
    }
};
