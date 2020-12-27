class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        vector<int> ans(m, 0);
        
        for (int j = 0; j < m; j++) {
            ans[j] = go(grid, 0, j, 1);
        }
        
        return ans;
    }
private:
    int n, m;
    bool point_valid(int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    int go(const vector<vector<int>>& grid, int i, int j, int state) {
        if (!point_valid(i, j)) return -1;
        if (i == n - 1 && state == 0) return j;
        
        if (grid[i][j] == 1) {
            if (state == 0) {
                return go(grid, i + 1, j, 1);
            } else {
                if (!point_valid(i, j + 1) || grid[i][j + 1] == -1) return -1;
                else return go(grid, i, j + 1, 0);
            }
        } else { // -1
            if (state == 0) {
                return go(grid, i + 1, j, 1);
            } else {
                if (!point_valid(i, j - 1) || grid[i][j - 1] == 1) return -1;
                else return go(grid, i, j - 1, 0);
            }
        }
    }
};
