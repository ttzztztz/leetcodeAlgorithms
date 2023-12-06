class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        const int n = mat.size(), m = mat[0].size();
        vector<vector<int>> transformed(n, vector<int>{});
        for (int i = 0; i < n; i++) {
            vector<int> r = mat[i];
            for (int j = 0; j < m; j++) {
                int idx = j;
                if (i % 2 == 1) {
                    idx = ((j - k) % m + m) % m;
                } else {
                    idx = (j + k) % m;
                }
                r[j] = mat[i][idx];
            }
            transformed[i] = r;
        }
        return mat == transformed;
    }
};