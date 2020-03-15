class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> answer;
        const int N = matrix.size(), M = matrix[0].size();
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int number = matrix[i][j];
                
                int row_min = 9999999, col_max = -99999999;
                for (int k = 0; k < M; k++) {
                    row_min = min(row_min, matrix[i][k]);
                }
                for (int k = 0; k < N; k++) {
                    col_max = max(col_max, matrix[k][j]);
                }
                
                if (row_min == number && col_max == number) answer.push_back(number);
            }
        }
        
        
        return answer;
    }
};
