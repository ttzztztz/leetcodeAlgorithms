class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty()) return 0;
        const int n = triangle.size();
        vector<int> f(n, 99999999);
        f[0] = triangle[0][0];
        // f[i][j] = max{f[i - 1][j - 1], f[i - 1][j]} + a[i][j]
        for (int i = 1; i < n; i++) {
            const int m = triangle[i].size();
            
            vector<int> g(n, 99999999);
            for (int j = 0; j < m; j++) {
                if (j >= 1) g[j] = min(f[j - 1], f[j]) + triangle[i][j];
                else g[j] = f[j] + triangle[i][j];
            }
            f = g;
        }
        return *min_element(f.begin(), f.end());
    }
};