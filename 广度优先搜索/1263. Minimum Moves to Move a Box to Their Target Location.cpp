class Point {
public:
    int x, y;

    Point() : x(0), y(0) {};

    Point(int a, int b) : x(a), y(b) {};

    bool operator==(const Point &p) const {
        return this->x == p.x && this->y == p.y;
    }
};

class Solution {
public:
    int N, M;

    bool canReach(const Point &start, const Point &end, const vector<vector<char>> &grid, const Point &box) {
        if (start == end) {
            return true;
        }

        deque<Point> current;
        vector<vector<bool>> visited(N + 3, vector<bool>(M + 3, false));
        visited[start.x][start.y] = true;

        current.push_back(start);
        while (!current.empty()) {
            Point p = current.front();
            current.pop_front();

            if (p == end) {
                return true;
            }

            const int dx[] = {0, 0, -1, 1};
            const int dy[] = {-1, 1, 0, 0};

            for (int i = 0; i < 4; i++) {
                const int nextX = p.x + dx[i], nextY = p.y + dy[i];
                if (!pointValid(Point(nextX, nextY)) || visited[nextX][nextY] || grid[nextX][nextY] == '#' || box == Point(nextX, nextY)) {
                    continue;
                }
                visited[nextX][nextY] = true;
                current.emplace_back(nextX, nextY);
            }
        }

        return false;
    }

    bool pointValid(const Point &p) {
        return p.x >= 0 && p.y >= 0 && p.x < N && p.y < M;
    }

    Point nextBox(Point current, int dir) {
        const int dx[] = {1, 0, 0, -1};
        const int dy[] = {0, 1, -1, 0};

        current.x += dx[dir], current.y += dy[dir];
        return current;
    }

    int minPushBox(vector<vector<char>> &grid) {
        Point start, target, box;
        N = grid.size(), M = grid[0].size();

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == 'S') {
                    grid[i][j] = '.';
                    start.x = i, start.y = j;
                } else if (grid[i][j] == 'B') {
                    grid[i][j] = '.';
                    box.x = i, box.y = j;
                } else if (grid[i][j] == 'T') {
                    grid[i][j] = '.';
                    target.x = i, target.y = j;
                }
            }
        }

        deque<tuple<Point, Point, int>> queue;
        set<tuple<int, int, int, int>> stateVisted;

        queue.emplace_back(start, box, 0);
        stateVisted.insert({start.x, start.y, box.x, box.y});
        while (!queue.empty()) {
            const tuple<Point, Point, int> t = queue.front();
            Point stateStart = get<0>(t), stateBox = get<1>(t);
            int step = get<2>(t);

            queue.pop_front();
            if (stateBox == target) {
                return step;
            }
            const int dx[] = {-1, 0, 0, 1};
            const int dy[] = {0, -1, 1, 0};

            for (int i = 0; i < 4; i++) {
                const Point adjacentBox = Point(stateBox.x + dx[i], stateBox.y + dy[i]);
                if (pointValid(adjacentBox) && canReach(adjacentBox, stateStart, grid, stateBox) && grid[adjacentBox.x][adjacentBox.y] == '.') {

                    Point next_box = nextBox(stateBox, i);
                    if (pointValid(next_box) && grid[next_box.x][next_box.y] == '.') {
                        if (!stateVisted.count({stateBox.x, stateBox.y, next_box.x, next_box.y})) {
                            stateVisted.insert({stateBox.x, stateBox.y, next_box.x, next_box.y});
                            queue.emplace_back(stateBox, next_box, step + 1);
                        }
                    }

                }
            }

        }
        return -1;
    }
};