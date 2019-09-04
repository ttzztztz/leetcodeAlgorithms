class Solution {
public:
    int dp_left[300][300];
    int dp_right[300][300];
    int dp_up[300][300];

    int maximalSquare(vector<vector<char>>& matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                dp_left[i][j] = j;
                dp_right[i][j] = j;
                if (matrix[i][j] == '1') {
                    dp_up[i][j] = 1;
                } else {
                    dp_up[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[i].size(); j++) {
                if (matrix[i][j] == '1' && matrix[i][j] == matrix[i][j - 1]) {
                    dp_left[i][j] = dp_left[i][j - 1];
                }
            }
        }

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = matrix[i].size() - 2; j >= 0; j--) {
                if (matrix[i][j] == '1' && matrix[i][j] == matrix[i][j + 1]) {
                    dp_right[i][j] = dp_right[i][j + 1];
                }
            }
        }

        int answer = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (i >= 1 && matrix[i][j] == matrix[i - 1][j] && matrix[i][j] == '1') {
                    dp_left[i][j] = std::max(dp_left[i][j], dp_left[i - 1][j]);
                    dp_right[i][j] = std::min(dp_right[i][j], dp_right[i - 1][j]);

                    dp_up[i][j] = dp_up[i - 1][j] + 1;
                }

                int a = dp_right[i][j] - dp_left[i][j] + 1;
                int b = dp_up[i][j];
                int temp = std::min(a, b);

                answer = std::max(answer, temp * temp);
            }
        }

        return answer;
    }
};