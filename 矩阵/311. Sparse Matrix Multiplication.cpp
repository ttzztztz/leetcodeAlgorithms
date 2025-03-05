class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        if (mat1.empty() || mat1[0].empty() || mat2.empty() || mat2[0].empty()) return {};
        const int n = mat1.size(), t = mat1[0].size(), m = mat2[0].size();

        const vector<vector<pair<int, int>>> m1 = compress_matrix(mat1);
        const vector<vector<pair<int, int>>> m2 = compress_matrix(mat2);

        vector<vector<int>> ans(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) for (auto [k, val1] : m1[i]) {
            for (auto [j, val2] : m2[k]) {
                ans[i][j] += val1 * val2;
            }
        }
        return ans;
    }
private:
    vector<vector<pair<int, int>>> compress_matrix(const vector<vector<int>>& mat) {
        if (mat.empty()) return {};

        const int n = mat.size(), m = mat[0].size();
        vector<vector<pair<int, int>>> ans;
        for (int i = 0; i < n; i++) {
            ans.push_back({});
            for (int j = 0; j < m; j++) {
                if (mat[i][j] != 0) {
                    ans.back().emplace_back(j, mat[i][j]);
                }
            }
        }
        return ans;
    }
};