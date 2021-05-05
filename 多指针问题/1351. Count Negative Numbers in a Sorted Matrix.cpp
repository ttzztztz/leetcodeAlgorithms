class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        if (grid.empty()) return ans;
        const int n = grid.size(), m = grid[0].size();
        
        for (int i = 0, j = m - 1; i < n; i++) {
            while (j >= 0 && grid[i][j] < 0) j--;
            ans += max(0, m - j - 1);
        }
        return ans;
    }
};