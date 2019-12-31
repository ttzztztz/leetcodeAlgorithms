class Point {
public:
    double x, y;
    Point() : x(0), y(0) {};
    Point(double _x, double _y) : x(_x), y(_y) {};
    bool operator<(const Point& $2) const {
        if (this->x == $2.x) {
            return this->y < $2.y;
        } else {
            return this->x < $2.x;
        }
    }
};

class Solution {
public:
    double dist(const Point& $1, const Point& $2) {
        return sqrt(($1.x - $2.x) * ($1.x - $2.x) + ($1.y - $2.y) * ($1.y - $2.y));
    }
    double minAreaFreeRect(vector<vector<int>>& points) {
        double answer = std::numeric_limits<double>::max();
        bool find = false;
        
        map<double, map<Point, vector<pair<Point, Point>>>> pointMap;
        const int N = points.size();
        for (int i = 0; i < N; i++) {
            const Point $1 = Point(points[i][0], points[i][1]);
            for (int j = i + 1; j < N; j++) {
                const Point $2 = Point(points[j][0], points[j][1]);
                const Point middle = Point((points[i][0] + points[j][0]) / 2.0, (points[i][1] + points[j][1]) / 2.0);
                
                const double distance = dist($1, $2);
                pointMap[distance][middle].emplace_back($1, $2);
            }
        }
        
        for (const pair<double, map<Point, vector<pair<Point, Point>>>>& pointMiddleSet : pointMap) {
            for (const pair<Point, vector<pair<Point, Point>>>& pointSet : pointMiddleSet.second) {
                const int M = pointSet.second.size();
                for (int i = 0; i < M; i++) {
                    for (int j = i + 1; j < M; j++) {
                        const double dist1 = dist(pointSet.second[i].first, pointSet.second[j].second);
                        const double dist2 = dist(pointSet.second[i].first, pointSet.second[j].first);
                        
                        find = true;
                        answer = min(answer, dist1 * dist2);
                    }
                }
            }
        }
        
        if (!find) return 0;
        return answer;
    }
};
