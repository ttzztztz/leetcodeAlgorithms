class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        const int n = matrix.size(), m = matrix[0].size();
        int l = 0, r = n * m - 1;
        while (l <= r) {
            const int mid = (l + r) / 2;

            const int x = mid / m, y = mid % m;
            if (matrix[x][y] < target) l = mid + 1;
            else r = mid - 1;
        }

        if (l >= n * m) return false;
        return matrix[l / m][l % m] == target;
    }
};