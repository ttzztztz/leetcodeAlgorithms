class Point {
public:
    int x, y;
    long long dist() const {
        return (this->x * this->x) + (this->y * this->y);
    }
    Point() : x(0), y(0) {};
    Point(int a, int b) : x(a), y(b) {};
    bool operator< (const Point& p2) const {
        return this->dist() < p2.dist();
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> answer;
        priority_queue<Point> heap;
        for (int i = 0; i < points.size(); i++) {
            const int x = points[i][0], y = points[i][1];

            heap.push(Point(x, y));
            if (heap.size() > K) {
                heap.pop();
            }
        }

        while (heap.size() > 0) {
            const Point p = heap.top();
            heap.pop();

            vector<int> oneAnswer = {p.x, p.y};
            answer.push_back(oneAnswer);
        }
        return answer;
    }
};