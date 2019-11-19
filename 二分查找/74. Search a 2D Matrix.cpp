class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }

        const int N = matrix.size(), M = matrix[0].size();
        // first binary search
        int left = 0, right = N - 1;
        while (left <= right) {
            const int middle = (left + right) >> 1;
            if (matrix[middle][0] <= target) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
        int find = left - 1;

        if (find < 0) {
            return false;
        } else if (matrix[find][0] == target) {
            return true;
        } else if(matrix[find][0] > target) {
            find--;
        }

        if (find < 0) {
            return false;
        }
        // second binary search
        left = 0, right = M - 1;
        while (left <= right) {
            const int middle = (left + right) >> 1;
            if (matrix[find][middle] <= target) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }

        const int find2 = left - 1;
        if (find2 < 0) {
            return false;
        }
        return matrix[find][find2] == target;
    }
};