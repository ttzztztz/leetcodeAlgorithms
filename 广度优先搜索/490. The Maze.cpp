class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if (maze.empty() || maze[0].empty()) return false;
        n = maze.size(), m = maze[0].size();
        const int dx[] = { 0, 0, -1, 1 };
        const int dy[] = { -1, 1, 0, 0 };

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        deque<Point> q = { { start[0], start[1] } };
        visited[start[0]][start[1]] = true;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop_front();

            if (x == destination[0] && y == destination[1]) return true;
            for (int k = 0; k < 4; k++) {
                auto [nx, ny] = next_point(maze, { x, y }, dx[k], dy[k]);
                if (!point_valid(nx, ny) || visited[nx][ny]) continue;
                visited[nx][ny] = true;
                if (nx == destination[0] && ny == destination[1]) return true;
                q.emplace_back(nx, ny);
            }
        }
        return false;
    }
private:
    typedef pair<int, int> Point;
    int n, m;

    bool point_valid(int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    Point next_point(const vector<vector<int>>& maze, const Point& current, int dx, int dy) {
        auto [x, y] = current;
        while (point_valid(x + dx, y + dy) && maze[x + dx][y + dy] == 0) {
            x += dx, y += dy;
        }
        return { x, y };
    }
};