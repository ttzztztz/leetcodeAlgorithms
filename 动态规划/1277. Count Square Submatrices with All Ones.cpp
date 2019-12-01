class Solution {
public:
    int dp_right[305][305];
    int countSquares(vector<vector<int>>& matrix) {
        int answer = 0;
        const int N = matrix.size(), M = matrix[0].size();

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                dp_right[i][j] = j;
            }
        }

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = matrix[i].size() - 2; j >= 0; j--) {
                if (matrix[i][j + 1] == matrix[i][j] && matrix[i][j] == 1) {
                    dp_right[i][j] = dp_right[i][j + 1];
                }
            }
        }

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                int minC = dp_right[i][j] - j + 1;
                int tmp = 0;

                for (int h = i; h < matrix.size(); h++) {
                    if (matrix[h][j] == 0) {
                        break;
                    }

                    minC = min(minC, dp_right[h][j] - j + 1);
                    if (minC >= h - i + 1) {
                        tmp += 1;
                    }
                }

                answer += tmp;
            }
        }

        return answer;
    }
};