class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if (matrix.empty() || matrix[0].empty()) return -1;

        long long l = numeric_limits<int>::min(), r = numeric_limits<int>::max();
        while (l <= r) {
            const long long mid = (l + r) / 2;

            const int target = solve(matrix, mid);
            if (target < k) l = mid + 1;
            else r = mid - 1;
        }
        return l;
    }
private:
    int solve(const vector<vector<int>>& matrix, int target) {
        int ans = 0;
        for (int i = 0, j = matrix[0].size() - 1; i < matrix.size(); i++) {
            while (j >= 0 && matrix[i][j] > target) j--;
            ans += j + 1;
        }
        return ans;
    }
};