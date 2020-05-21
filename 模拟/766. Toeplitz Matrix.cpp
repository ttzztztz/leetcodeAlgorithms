class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        const int N = matrix.size(), M = matrix[0].size();
        for (int i = 0; i < N; i++) {
            int x = i, y = 0;
            const int val = matrix[x][y];
            while (x < N && y < M) {
                if (matrix[x][y] != val) return false;
                x++, y++;
            }
        }
        for (int j = 0; j < M; j++) {
            int x = 0, y = j;
            const int val = matrix[x][y];
            while (x < N && y < M) {
                if (matrix[x][y] != val) return false;
                x++, y++;
            }
        }
        
        return true;
    }
};
