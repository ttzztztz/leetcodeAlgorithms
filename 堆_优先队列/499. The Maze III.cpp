class Solution {
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        if (maze.empty() || maze[0].empty()) return impossible;
        n = maze.size(), m = maze[0].size();

        // [ 'd', 'l', 'r', 'u' ]
        const int dx[] = { 1, 0, 0, -1 };
        const int dy[] = { 0, -1, 1, 0 };
        const char op[] = { 'd', 'l', 'r', 'u' };

        vector<vector<int>> dist(n, vector<int>(m, -1));
        vector<vector<string>> parent_op(n, vector<string>(m, ""));

        typedef tuple<int, string, int, int> State; // { dist, operation, x, y }
        priority_queue<State, vector<State>, greater<>> pq;
        pq.emplace(0, "", ball[0], ball[1]);
        dist[ball[0]][ball[1]] = 0;

        while (!pq.empty()) {
            auto [d, operation, x, y] = pq.top();
            pq.pop();

            if (x == hole[0] && y == hole[1]) return operation;
            for (int k = 0; k < 4; k++) {
                auto [nx, ny] = next_point(maze, hole, {x, y}, dx[k], dy[k]);
                if (nx == x && ny == y) continue;

                const int added_dist = abs(x - nx) + abs(y - ny);
                const char o = op[k];
                
                if (
                    dist[nx][ny] == -1
                    || d + added_dist < dist[nx][ny]
                    || parent_op[nx][ny] > operation + o
                ) {
                    dist[nx][ny] = d + added_dist;
                    parent_op[nx][ny] = operation + o;
                    pq.emplace(d + added_dist, operation + o, nx, ny);
                }
            }
        }
        return impossible;
    }
private:
    typedef pair<int, int> Point;
    const string impossible = "impossible";
    int n, m;

    bool point_valid(int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    Point next_point(const vector<vector<int>>& maze, const vector<int>& hole, const Point& cur, int dx, int dy) {
        auto [x, y] = cur;
        while (point_valid(x + dx, y + dy) && maze[x + dx][y + dy] == 0) {
            x += dx, y += dy;
            if (x == hole[0] && y == hole[1]) return { x, y };
        }
        return { x, y };
    }
};