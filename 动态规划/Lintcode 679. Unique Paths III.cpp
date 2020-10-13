class Solution {
public:
    /*
     * @param : an array of arrays
     * @return: the sum of all unique weighted paths
     */
    int uniqueWeightedPaths(vector<vector<int>>& grid) {
        const int n = grid.size();
        if (n == 0) return 0;
        const int m = grid[0].size();
        if (m == 0) return 0;
        
        vector<vector<unordered_set<int>>> f(n + 1, vector<unordered_set<int>>(m + 1));
        f[0][1] = f[1][0] = unordered_set<int>{0};
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                unordered_set<int> tmp;
                
                const auto& val = grid[i - 1][j - 1];
                if (i - 1 >= 0) {
                    for (auto& v : f[i - 1][j]) tmp.insert(v + val);
                }
                if (j - 1 >= 0) {
                    for (auto& v : f[i][j - 1]) tmp.insert(v + val);
                }
                
                f[i][j] = tmp;
            }
        }
        
        int ans = 0;
        for (auto& v : f[n][m]) ans += v;
        return ans;
    }
};
