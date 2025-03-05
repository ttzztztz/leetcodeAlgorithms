class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
                if (maze.empty() || maze[0].empty()) return false;
        n = maze.size(), m = maze[0].size();
        const int dx[] = { 0, 0, -1, 1 };
        const int dy[] = { -1, 1, 0, 0 };

        vector<vector<int>> dist(n, vector<int>(m, -1));
        typedef tuple<int, int, int> State; // { dist, x, y }
        priority_queue<State, vector<State>, greater<>> q;
        q.emplace(0, start[0], start[1]);
        dist[start[0]][start[1]] = 0;
        while (!q.empty()) {
            auto [d, x, y] = q.top();
            q.pop();

            if (x == destination[0] && y == destination[1]) return d;
            for (int k = 0; k < 4; k++) {
                auto [nx, ny] = next_point(maze, { x, y }, dx[k], dy[k]);
                if (!point_valid(nx, ny)) continue;
                const int delta_dist = abs(x - nx) + abs(y - ny);
                if (dist[nx][ny] == -1 || d + delta_dist < dist[nx][ny]) {
                    dist[nx][ny] = d + delta_dist;
                    q.emplace(d + delta_dist, nx, ny);
                }
            }
        }
        return -1;
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