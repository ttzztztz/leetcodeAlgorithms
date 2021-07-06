class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if (mat.empty()) return {};
        const int n = mat.size(), m = mat[0].size();
        if (n * m != r * c) return mat;
        
        vector<vector<int>> ans(r, vector<int>(c, 0));
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            const int id = i * m + j;
            ans[id / c][id % c] = mat[i][j];
        }
        return ans;
    }
};