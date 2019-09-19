class NumMatrix {
public:
    vector<vector<int>> dp;
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.size() != 0) {
            dp.resize(matrix.size());

            for (int i = 0; i < matrix.size(); i++) {
                dp[i].resize(matrix[0].size());
            }

            for (int i = 0; i < matrix[0].size(); i++) {
                if (i == 0) {
                    dp[0][i] = matrix[0][i];
                } else {
                    dp[0][i] = dp[0][i - 1] + matrix[0][i];
                }
            }

            for (int i = 0; i < matrix.size(); i++) {
                if (i == 0) {
                    dp[i][0] = matrix[i][0];
                } else {
                    dp[i][0] = dp[i - 1][0] + matrix[i][0];
                }
            }

            for (int i = 1; i < matrix.size(); i++) {
                for (int j = 1; j < matrix[i].size(); j++) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + matrix[i][j];
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 != 0 && col1 != 0) {
            return dp[row2][col2] + dp[row1 - 1][col1 - 1] - dp[row2][col1 - 1] - dp[row1 - 1][col2];
        } else if (row1 == 0 && col1 != 0) {
            return dp[row2][col2] - dp[row2][col1 - 1];
        } else if (row1 != 0 && col1 == 0) {
            return dp[row2][col2] - dp[row1 - 1][col2];
        } else {
            return dp[row2][col2];
        }
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */