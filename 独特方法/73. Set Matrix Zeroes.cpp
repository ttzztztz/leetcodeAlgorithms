class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty()) return;
        
        const int N = matrix.size(), M = matrix[0].size();
        int first = 0, second = 0;
        for (int i = 0; i < N; i++) {
            if (matrix[i][0] == 0) first = true;
        }
        for (int j = 0; j < M; j++) {
            if (matrix[0][j] == 0) second = true;
        }
        
        for (int i = 1; i < N; i++) {
            for (int j = 1; j < M; j++) {
                if (matrix[i][j] == 0) matrix[i][0] = matrix[0][j] = 0;
            }
        }
        
        for (int i = 1; i < N; i++) {
            for (int j = 1; j < M; j++) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0) matrix[i][j] = 0;
            }
        }
        
        if (first) {
            for (int i = 0; i < N; i++) {
                matrix[i][0] = 0;
            }
        }
        
        if (second) {
            for (int j = 0; j < M; j++) {
                matrix[0][j] = 0;
            }
        }
    }
};
