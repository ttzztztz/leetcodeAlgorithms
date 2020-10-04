class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int ans = 0, ext = 0;
        const int n = points.size();
        const double PI = 3.14159265359, eps = 1e-9;
        vector<double> v;
        for (int i = 0; i < n; i++) {
            const int x = points[i][0], y = points[i][1];
            if (x == location[0] && y == location[1]) ext++;
            else v.push_back(atan2(y - location[1], x - location[0]) * 180.0 / PI);
        }
        
        for (int i = 0, m = v.size(); i < m; i++) {
            v.push_back(v[i] + 360.0);
        }
        sort(v.begin(), v.end());
        
        for (int l = 0, r = 0; r < v.size(); r++) {
            while (l < r && v[r] - v[l] >= eps + angle) l++;
            ans = max(ans, r - l + 1);
        }
        return ans + ext;
    }
};
