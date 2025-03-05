class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        vector<int> all_x, all_y;
        const int n = grid.size(), m = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (grid[i][j] == 1) {
            all_x.push_back(i);
            all_y.push_back(j);
            cnt++;
        }

        sort(all_x.begin(), all_x.end());
        sort(all_y.begin(), all_y.end());

        const int target_x = all_x[cnt / 2];
        const int target_y = all_y[cnt / 2];

        int ans = 0;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (grid[i][j] == 1) {
            ans += abs(i - target_x) + abs(j - target_y);
        }
        return ans;
    }
};