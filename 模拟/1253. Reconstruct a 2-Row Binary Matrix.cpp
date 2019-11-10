class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        const int N = colsum.size();
        vector<vector<int>> matrix(2, vector<int>(N, -1));
        vector<int> needJudgeCol;
        int currentUpper = 0, currentLower = 0;
        for (int i = 0; i < N; i++) {
            const int sum = colsum[i];
            if (sum == 2) {
                matrix[0][i] = matrix[1][i] = 1;
                currentUpper++;
                currentLower++;
            } else if (sum == 1) {
                needJudgeCol.push_back(i);
            } else { // sum == 0
                matrix[0][i] = matrix[1][i] = 0;
            }
        }

        for (const int col : needJudgeCol) {
            if (currentUpper > upper || currentLower > lower) {
                return vector<vector<int>>();
            }

            if (currentUpper < upper) {
                currentUpper++;
                matrix[0][col] = 1;
                matrix[1][col] = 0;
            } else if (currentLower < lower) {
                currentLower++;
                matrix[1][col] = 1;
                matrix[0][col] = 0;
            } else {
                return vector<vector<int>>();
            }
        }

        if (currentUpper != upper || currentLower != lower) {
            return vector<vector<int>>();
        }

        return matrix;
    }
};