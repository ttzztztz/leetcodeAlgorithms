class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        const int n = matrix.size(), m = matrix[0].size();
        vector<int> r(n), c(m);
        
        for (int i = 0; i < n; i++) {
            r[i] = matrix[i][0];
            for (int j = 1; j < m; j++) {
                r[i] = min(r[i], matrix[i][j]);
            }
        }
        
        for (int j = 0; j < m; j++) {
            c[j] = matrix[0][j];
            for (int i = 1; i < n; i++) {
                c[j] = max(c[j], matrix[i][j]);
            }
        }
        
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (r[i] == c[j]) ans.push_back(matrix[i][j]);
            }
        }
        return ans;
    }
};