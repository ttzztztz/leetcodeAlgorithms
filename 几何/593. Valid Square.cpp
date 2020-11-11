class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        // 核心：按照横坐标为第一关键字，纵坐标为第二关键字，对所有的点排序，然后画图，可以发现规律
        vector<Point> points = { p1, p2, p3, p4 };
        sort(points.begin(), points.end(), [](const auto& $1, const auto& $2) -> bool {
            return $1[0] < $2[0] || ($1[0] == $2[0] && $1[1] < $2[1]);
        });
        
        const vector<pair<int, int>> cmp1 = { {0, 1}, {1, 3}, {2, 3}, {0, 2} }, cmp2 = { {0, 3}, {1, 2} };
        
        for (int i = 1; i < cmp1.size(); i++) {
            const auto [i1, i2] = cmp1[i];
            const auto [i3, i4] = cmp1[i - 1];
            
            const double d1 = dist(points[i1], points[i2]), d2 = dist(points[i3], points[i4]);
            if (d1 != d2 || d1 == 0 || d2 == 0) return false;
        }
        
        for (int i = 1; i < cmp2.size(); i++) {
            const auto [i1, i2] = cmp2[i];
            const auto [i3, i4] = cmp2[i - 1];
            
            const double d1 = dist(points[i1], points[i2]), d2 = dist(points[i3], points[i4]);
            if (d1 != d2 || d1 == 0 || d2 == 0) return false;
        }
        
        return true;
    }
private:
    typedef vector<int> Point;
    double dist(const Point& $1, const Point& $2) {
        double x1 = $1[0], x2 = $2[0], y1 = $1[1], y2 = $2[1];
        
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }
};
