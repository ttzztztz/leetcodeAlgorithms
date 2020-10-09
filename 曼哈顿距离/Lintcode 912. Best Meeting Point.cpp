class Solution {
public:
    /**
     * @param grid: a 2D grid
     * @return: the minimize travel distance
     */
    int minTotalDistance(vector<vector<int>> &grid) {
        int ans = 0, n = 0;
        vector<vector<int>> g1;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    n++;
                    g1.push_back(vector<int>{i, j});
                }
            }
        }
        
        sort(g1.begin(), g1.end(), [](const auto& $1, const auto& $2) -> bool {
            return $1[0] < $2[0];
        });
        
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            ans += g1[j][0] - g1[i][0];
        }
        
        sort(g1.begin(), g1.end(), [](const auto& $1, const auto& $2) -> bool {
            return $1[1] < $2[1];
        });
        
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            ans += g1[j][1] - g1[i][1];
        }
        
        return ans;
    }
};
