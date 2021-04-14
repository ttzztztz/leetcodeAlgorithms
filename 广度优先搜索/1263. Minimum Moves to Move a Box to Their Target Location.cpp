const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

class Solution {
public:
    int minPushBox(vector<vector<char>>& grid) {
        if (grid.empty()) return -1;
        n = grid.size(), m = grid[0].size();
        this->g = grid;
        
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'S') s = {i, j};
            else if (grid[i][j] == 'B') b = {i, j};
            else if (grid[i][j] == 'T') e = {i, j};
        }

        bool visited[n + 1][m + 1][4];
        memset(visited, 0, sizeof visited);

        int d = 0;
        deque<State> q;
        for (int k = 0; k < 4; k++) {
            Point end = { b.first + dx[k], b.second + dy[k] };
            if (can_reach(s, b, end)) q.emplace_back(b.first + dx[k], b.second + dy[k], k);
        }

        while (!q.empty()) {
            const int cnt = q.size();
            for (int _ = 0; _ < cnt; _++) {
                auto [x, y, k] = q.front();
                visited[x][y][k] = true;
                q.pop_front();

                if (make_pair(x, y) == e) return d;
                const int nx = x + (-1) * dx[k], ny = y + (-1) * dy[k];
                if (point_valid(nx, ny) && g[nx][ny] != '#') {
                    for (int nk = 0; nk < 4; nk++) {
                        if (
                            can_reach({x, y}, {nx, ny}, {nx + dx[nk], ny + dy[nk]})
                            && !visited[nx][ny][nk]
                        ) {
                            visited[nx][ny][nk] = true;
                            if (make_pair(nx, ny) == e) return d;
                            q.emplace_back(nx, ny, nk);
                        }
                    }
                }
            }
            d++;
        }
        return -1;
    }
private:
    typedef pair<int, int> Point;
    typedef tuple<int, int, int> State;
    int n, m;
    Point s, e, b;
    vector<vector<char>> g;
    
    bool point_valid(int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    
    bool can_reach(const Point& start, const Point& box, const Point& end) {
        if (!point_valid(start.first, start.second) || !point_valid(end.first, end.second) || g[start.first][start.second] == '#' || g[end.first][end.second] == '#') return false;

        deque<Point> q = {start};
        bool visited[n + 1][m + 1];
        memset(visited, 0, sizeof visited);
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop_front();
            visited[x][y] = true;
            if (make_pair(x, y) == end) return true;
            
            for (int k = 0; k < 4; k++) {
                const int nx = x + dx[k], ny = y + dy[k];
                if (!point_valid(nx, ny) || visited[nx][ny] || g[nx][ny] == '#' || make_pair(nx, ny) == box) continue;
                visited[nx][ny] = true;
                if (make_pair(nx, ny) == end) return true;
                q.emplace_back(nx, ny);
            }
        }
        return false;
    }
};