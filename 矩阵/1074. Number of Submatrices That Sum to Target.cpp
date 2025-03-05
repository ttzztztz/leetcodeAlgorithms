class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        const int n = matrix.size(), m = matrix[0].size();
        int ans = 0;
        vector<vector<int>> psum(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            psum[i][j] = matrix[i][j];
            if (j - 1 >= 0) psum[i][j] += psum[i][j - 1];
        }

        for (int j1 = 0; j1 < m; j1++) for (int j2 = j1; j2 < m; j2++) {
            unordered_map<int, int> cnt;
            cnt[0] = 1;
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += psum[i][j2];
                if (j1 - 1 >= 0) sum -= psum[i][j1 - 1];

                if (cnt.count(sum - target)) ans += cnt[sum - target];
                cnt[sum]++;
            }
        }
        return ans;
    }
};