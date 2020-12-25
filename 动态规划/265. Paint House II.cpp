class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;

        const int n = costs.size(), k = costs[0].size();
        vector<vector<int>> f(n, vector<int>(k + 2, numeric_limits<int>::max())), g(n, vector<int>(k + 2, numeric_limits<int>::max())), h(n, vector<int>(k + 2, numeric_limits<int>::max()));
        
        for (int j = 1; j <= k; j++) {
            f[0][j] = costs[0][j - 1];
        }
        for (int j = 1; j <= k; j++) {
            g[0][j] = min(g[0][j - 1], f[0][j]);
        }
        for (int j = k; j >= 1; j--) {
            h[0][j] = min(h[0][j + 1], f[0][j]);
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                f[i][j] = min(g[i - 1][j - 1], h[i - 1][j + 1]) + costs[i][j - 1];
            }
            
            for (int j = 1; j <= k; j++) {
                g[i][j] = min(g[i][j - 1], f[i][j]);
            }
            
            for (int j = k; j >= 1; j--) {
                h[i][j] = min(h[i][j + 1], f[i][j]);
            }
        }
        
        int ans = numeric_limits<int>::max();
        for (int i = 1; i <= k; i++) {
            ans = min(ans, f[n - 1][i]);
        }
        return ans;
    }
};
