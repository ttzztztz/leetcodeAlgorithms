class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int ans = -1;
        pair<int, int> prev = {-1, -1};
        pair<int, int> invalid = prev;
        
        for (int i = 0; i < points.size(); i++) {
            auto& p = points[i];
            if (p[0] == x || p[1] == y) {
                if (prev == invalid || abs(p[0] - x) + abs(p[1] - y) < abs(prev.first - x) + abs(prev.second - y)) {
                    ans = i;
                    prev = {p[0], p[1]};
                }
            }
        }
        return ans;
    }
};
