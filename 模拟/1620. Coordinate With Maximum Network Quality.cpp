class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        const int n = towers.size();
        
        vector<int> ans = {-1, -1};
        int ans_sum = -1;
        
        for (int i = 0; i < n; i++) {
            int x = towers[i][0], y = towers[i][1];
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                const int a = towers[j][0], b = towers[j][1];
                const int d2 = (a - x) * (a - x) + (b - y) * (b - y);
                if (d2 <= radius * radius) {
                    cnt += towers[j][2] / (1 + sqrt(d2));
                }
            }
            
            if (cnt == ans_sum) {
                if (x < ans[0] || (x == ans[0] && y < ans[1])) ans = { x, y };
            } else if (cnt > ans_sum) {
                ans_sum = cnt;
                ans = { x, y };
            }
        }
        
        return ans;
    }
};
