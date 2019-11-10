class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        int answer = 0;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (const vector<int>& index : indices) {
            const int r = index[0], c = index[1];

            for (int i = 0; i < m; i++) {
                matrix[r][i]++;
            }
            for (int i = 0; i < n; i++) {
                matrix[i][c]++;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] & 1) {
                    answer++;
                }
            }
        }
        return answer;
    }
};