class Solution {
public:
    /**
     * @param matrix: a matrix
     * @return: return true if same.
     */
    bool judgeSame(vector<vector<int>> &matrix) {
        N = matrix.size(), M = matrix[0].size();
        for (int i = 0; i < N; i++) {
            if (!judge(matrix, i, 0)) return false;
        }
        for (int j = 1; j < M; j++) {
            if (!judge(matrix, 0, j)) return false;
        }
        return true;
    }
private:
    int N, M;
    bool pointValid(int i, int j) {
        return i >= 0 && j >= 0 && i < N && j < M;
    }
    bool judge(const vector<vector<int>> &matrix, int i, int j) {
        const int raw = matrix[i][j];
        while (pointValid(i, j)) {
            if (matrix[i][j] != raw) return false;
            i++, j++;
        }
        return true;
    }
};
