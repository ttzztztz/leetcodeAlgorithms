class Solution {
public:
    /**
     * @param dungeon: a 2D array
     * @return: return a integer
     */
    int calculateMinimumHP(vector<vector<int>> &dungeon) {
        // write your code here
        const int n = dungeon.size(), m = dungeon[0].size();
        int f[n + 1][m + 1];
        memset(f, 0x3f, sizeof f);
        f[n][m - 1] = f[n - 1][m] = 1;
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                f[i][j] = max(1, min(f[i + 1][j], f[i][j + 1]) - dungeon[i][j]);
            }
        }
        
        return f[0][0];
    }
};
