class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        const int n = grid.size(), m = grid[0].size();
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int cnt = 0;
                for (int k = 0; k < m; k++) {
                    if (grid[i][k] == 1 && grid[j][k] == 1) {
                        cnt++;
                    }
                }
                
                ans += cnt * (cnt - 1) / 2;
            }
        }
        return ans;
    }
};
