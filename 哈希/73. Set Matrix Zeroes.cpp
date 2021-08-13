class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty()) return;
        const int n = matrix.size(), m = matrix[0].size();
        vector<int> r(n, 0), c(m, 0);
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) r[i] = c[j] = 1;
        }
        
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            if (r[i] || c[j]) matrix[i][j] = 0;
        }
    }
};
