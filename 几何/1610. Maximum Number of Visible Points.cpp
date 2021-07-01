class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int ans = 0, extra = 0;
        
        const int x0 = location[0], y0 = location[1];
        const double EPS = 1e-9;
        
        vector<double> v;
        const double PI = 3.14159265359;
        for (auto& point : points) {
            const int x = point[0], y = point[1];
            if (x == x0 && y == y0) {
                extra++;
            } else {
                const double alpha = atan2(y - y0, x - x0) * 180.0 / PI;
                
                v.push_back(alpha);
                v.push_back(alpha + 360.0);
            }
        }
        
        sort(v.begin(), v.end());
        const int n = v.size();
        for (int l = 0, r = 0; r < n; r++) {
            while (v[r] - v[l] - EPS >= 1.0 * angle) l++;
            ans = max(ans, r - l + 1);
        }
        return ans + extra;
    }
};