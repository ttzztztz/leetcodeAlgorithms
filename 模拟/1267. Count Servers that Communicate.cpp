class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        const int n = grid.size(), m = grid[0].size();
        
        vector<int> r(n, 0), c(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) r[i]++, c[j]++;
            }
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] && (r[i] >= 2 || c[j] >= 2)) ans++;
            }
        }
        return ans;
    }
};