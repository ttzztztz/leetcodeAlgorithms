class Point {
public:
    int x, y, h;
    Point() : x(0), y(0), h(0) {};
    Point(int _x, int _y, int _h) : x(_x), y(_y), h(_h) {};
    bool operator< (const Point& $2) const {
        return this->h > $2.h;
    }
};

class Solution {
public:
    int m, n;
    bool pointValid(int x, int y) {
        return x >= 0 && y >= 0 && x < m && y < n;
    }
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.size() <= 2 || heightMap[0].size() <= 2) {
            return 0;
        }

        m = heightMap.size(), n = heightMap[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<Point> heap;
        int answer = 0;

        const int dx[] = {0, 0, 1, -1};
        const int dy[] = {1, -1, 0, 0};

        for (int i = 0; i < m; i++) {
            heap.push(Point(i, 0, heightMap[i][0]));
            heap.push(Point(i, n - 1, heightMap[i][n - 1]));

            visited[i][0] = visited[i][n - 1] = true;
        }
        for (int i = 0; i < n; i++) {
            heap.push(Point(0, i, heightMap[0][i]));
            heap.push(Point(m - 1, i, heightMap[m - 1][i]));

            visited[0][i] = visited[m - 1][i] = true;
        }

        while (!heap.empty()) {
            Point p = heap.top();
            heap.pop();

            for (int i = 0; i < 4; i++) {
                const int nextX = p.x + dx[i], nextY = p.y + dy[i];

                if (pointValid(nextX, nextY) && !visited[nextX][nextY]) {
                    visited[nextX][nextY] = true;
                    answer += std::max(0, p.h - heightMap[nextX][nextY]);
                    heap.push(Point(nextX, nextY, std::max(p.h, heightMap[nextX][nextY])));
                }
            }
        }

        return answer;
    }
};