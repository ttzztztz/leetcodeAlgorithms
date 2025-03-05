class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty()) return true;

        n = matrix.size(), m = matrix[0].size();

        for (int i = 0; i < n; i++) if (!judge(matrix, i, 0)) return false;
        for (int i = 1; i < m; i++) if (!judge(matrix, 0, i)) return false;

        return true;
    }
private:
    int n, m;
    bool judge(const vector<vector<int>>& matrix, int i, int j) {
        for (int x = 1; i + x < n && j + x < m; x++) {
            if (matrix[i][j] != matrix[i + x][j + x]) return false;
        }
        return true;
    }
};