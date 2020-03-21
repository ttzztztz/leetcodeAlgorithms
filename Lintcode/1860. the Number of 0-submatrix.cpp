class Solution {
public:
    /**
     * @param matrix: a matrix
     * @return: Number of submatrices that are all 0
     */
    long long countSubmatrix(vector<vector<int>> &matrix) {
        long long answer = 0;
        const int N = matrix.size(), M = matrix[0].size();
        
        vector<vector<int>> f(N + 2, vector<int>(M + 2, 0));
        for (int i = 0; i < N; i++) {
            for (int j = M - 1; j >= 0; j--) {
                if (matrix[i][j] == 1) f[i][j] = 0;
                else f[i][j] = f[i][j + 1] + 1;
            }
        }
        
        for (int j = 0; j < M; j++) {
            long long square = 0;
            
            vector<pair<int, int>> stk;
            for (int i = 0; i < N; i++) {
                int width = 1;
                
                while (!stk.empty() && stk.back().first >= f[i][j]) {
                    int _length, _width;
                    tie(_length, _width) = stk.back();
                    
                    width += _width;
                    square -= _length * _width;
                    
                    stk.pop_back();
                }
                
                stk.emplace_back(f[i][j], width);
                square += width * f[i][j];
                answer += square;
            }
        }
        
        return answer;
    }
};
