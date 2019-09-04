int dp_left[1000][1000];
int dp_right[1000][1000];
int dp_top[1000][1000];

class Solution {
public:
    int maximalRectangle(vector <vector<char>> &matrix) {
        int answer = 0;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                dp_left[i][j] = j;
                dp_right[i][j] = j;
                if (matrix[i][j] == '1') {
                    dp_top[i][j] = 1;
                } else {
                    dp_top[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[i].size(); j++) {
                if (matrix[i][j - 1] == matrix[i][j] && matrix[i][j] == '1') {
                    dp_left[i][j] = dp_left[i][j - 1];
                }
            }
        }

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = matrix[i].size() - 2; j >= 0; j--) {
                if (matrix[i][j + 1] == matrix[i][j] && matrix[i][j] == '1') {
                    dp_right[i][j] = dp_right[i][j + 1];
                }
            }
        }


        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (i >= 1 && matrix[i - 1][j] == matrix[i][j] && matrix[i][j] == '1') {
                    dp_left[i][j] = std::max(dp_left[i][j], dp_left[i - 1][j]);
                    dp_right[i][j] = std::min(dp_right[i][j], dp_right[i - 1][j]);
                    dp_top[i][j] = dp_top[i - 1][j] + 1;
                }

                int a = dp_right[i][j] - dp_left[i][j] + 1;
                int b = dp_top[i][j];

                answer = std::max(answer, a * b);
            }
        }

        return answer;
    }
};