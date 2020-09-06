class Solution {
public:
    /**
     * @param n: the row of the matrix
     * @param m: the column of the matrix
     * @param after: the matrix
     * @return: restore the matrix
     */
    vector<vector<int>> matrixRestoration(int n, int m, vector<vector<int>> &after) {
        vector<vector<int>> answer(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                answer[i][j] = after[i][j];
                if (i >= 1) answer[i][j] -= after[i - 1][j];
                if (j >= 1) answer[i][j] -= after[i][j - 1];
                if (i >= 1 && j >= 1) answer[i][j] += after[i - 1][j - 1];
            }
        }
        return answer;
    }
};
