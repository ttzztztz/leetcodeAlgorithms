class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        const int N = matrix.size(), M = matrix[0].size();
        int x = N - 1, y = 0;
        while (x >= 0 && y < M) {
            if (matrix[x][y] == target) {
                return true;
            }

            if (matrix[x][y] > target) {
                x--;
            } else {
                y++;
            }
        }
        return false;
    }
};