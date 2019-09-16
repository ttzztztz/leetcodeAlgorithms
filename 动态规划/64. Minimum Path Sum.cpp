class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (i - 1 >= 0 && j - 1 >= 0) {
                    grid[i][j] += std::min(grid[i - 1][j], grid[i][j - 1]);
                } else if (i - 1 >= 0 && j - 1 < 0) {
                    grid[i][j] += grid[i - 1][j];
                } else if (i - 1 < 0 && j - 1 >= 0) {
                    grid[i][j] += grid[i][j - 1];
                }
            }
        }

        return grid[grid.size() - 1][grid[grid.size() - 1].size() - 1];
    }
};