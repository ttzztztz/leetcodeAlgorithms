class Point {
public:
    int x, y, height;
    Point() : x(0), y(0), height(0) {};
    Point(int a, int b, int h) : x(a), y(b), height(h) {};
    bool operator<(const Point& $2) const {
        return this->height > $2.height;
    }
};

class Solution {
public:
    bool visited[51][51];
    int N;
    inline bool pointValid(int x, int y) {
        return x >= 0 && y >= 0 && x < N && y < N && !visited[x][y];
    }
    int swimInWater(vector<vector<int>>& grid) {
        N = grid.size();
        priority_queue<Point> heap;
        std::memset(visited, 0, sizeof(visited));

        heap.push(Point(0, 0, grid[0][0]));
        int answer = 0;
        while (!heap.empty()) {
            Point p = heap.top();
            heap.pop();

            answer = std::max(answer, p.height);
            if (p.x == N - 1 && p.y == N - 1) {
                return answer;
            }

            if (pointValid(p.x - 1, p.y)) {
                visited[p.x - 1][p.y] = true;
                heap.push(Point(p.x - 1, p.y, grid[p.x - 1][p.y]));
            }
            if (pointValid(p.x + 1, p.y)) {
                visited[p.x + 1][p.y] = true;
                heap.push(Point(p.x + 1, p.y, grid[p.x + 1][p.y]));
            }
            if (pointValid(p.x, p.y - 1)) {
                visited[p.x][p.y - 1] = true;
                heap.push(Point(p.x, p.y - 1, grid[p.x][p.y - 1]));
            }
            if (pointValid(p.x, p.y + 1)) {
                visited[p.x][p.y + 1] = true;
                heap.push(Point(p.x, p.y + 1, grid[p.x][p.y + 1]));
            }
        }

        return answer;
    }
};