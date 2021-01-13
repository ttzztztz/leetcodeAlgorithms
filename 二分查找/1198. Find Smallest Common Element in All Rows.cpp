class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        const int n = mat.size(), m = mat[0].size();
        for (int i = 0; i < m; i++) {
            bool ok = true;
            for (int j = 1; j < n; j++) {
                auto it = lower_bound(mat[j].begin(), mat[j].end(), mat[0][i]);
                if (it == mat[j].end() || *it != mat[0][i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) return mat[0][i];
        }
        return -1;
    }
};
