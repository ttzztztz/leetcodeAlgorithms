class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        const int n = towers.size();
        
        vector<int> ans = {-1, -1};
        int ans_sum = -1;
        
        for (int x = -50; x <= 50; x++) {
            for (int y = -50; y <= 50; y++) {
                int cnt = 0;
                for (int j = 0; j < n; j++) {
                    const int a = towers[j][0], b = towers[j][1];
                    const int d = (a - x) * (a - x) + (b - y) * (b - y);
                    if (d <= radius * radius) {
                        cnt += towers[j][2] / (1 + sqrt(d));
                    }
                }

                if (cnt == ans_sum) {
                    if (x < ans[0] || (x == ans[0] && y < ans[1])) ans = { x, y };
                } else if (cnt > ans_sum) {
                    ans_sum = cnt;
                    ans = { x, y };
                }
            }
        }
        
        return ans;
    }
};
