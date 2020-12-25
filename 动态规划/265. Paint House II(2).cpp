class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;

        const int n = costs.size(), k = costs[0].size();
        vector<int> f(k + 2, numeric_limits<int>::max()), g(k + 2, numeric_limits<int>::max()), h(k + 2, numeric_limits<int>::max());
        
        for (int j = 1; j <= k; j++) {
            f[j] = costs[0][j - 1];
        }
        for (int j = 1; j <= k; j++) {
            g[j] = min(g[j - 1], f[j]);
        }
        for (int j = k; j >= 1; j--) {
            h[j] = min(h[j + 1], f[j]);
        }
        
        for (int i = 1; i < n; i++) {
            vector<int> f_next(k + 2, numeric_limits<int>::max()), g_next(k + 2, numeric_limits<int>::max()), h_next(k + 2, numeric_limits<int>::max());
            
            for (int j = 1; j <= k; j++) {
                f_next[j] = min(g[j - 1], h[j + 1]) + costs[i][j - 1];
            }
            
            for (int j = 1; j <= k; j++) {
                g_next[j] = min(g_next[j - 1], f_next[j]);
            }
            
            for (int j = k; j >= 1; j--) {
                h_next[j] = min(h_next[j + 1], f_next[j]);
            }
            
            f = f_next;
            g = g_next;
            h = h_next;
        }
        
        int ans = numeric_limits<int>::max();
        for (int i = 1; i <= k; i++) {
            ans = min(ans, f[i]);
        }
        return ans;
    }
};
