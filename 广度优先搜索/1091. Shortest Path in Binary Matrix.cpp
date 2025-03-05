class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        if (grid[0][0] == 1) return -1;

        const int n = grid.size(), m = grid[0].size();
        typedef pair<int, int> Point;
        const int dx[] = {0, 0, -1, 1, -1, -1, 1, 1};
        const int dy[] = {-1, 1, 0, 0, 1, -1, 1, -1};
        auto point_valid = [&](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < n && j < m;
        };

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        deque<Point> q = { {0, 0} };
        visited[0][0] = true;
        int ans = 1;
        while (!q.empty()) {
            const int cnt = q.size();
            for (int i = 0; i < cnt; i++) {
                const auto [x, y] = q.front();
                q.pop_front();

                if (x == n - 1 && y == n - 1) return ans;
                for (int k = 0; k < 8; k++) {
                    const int nx = x + dx[k], ny = y + dy[k];
                    if (!point_valid(nx, ny) || visited[nx][ny] || grid[nx][ny] == 1) continue;

                    if (nx == n - 1 && ny == n - 1) return ans + 1;
                    visited[nx][ny] = true;
                    q.emplace_back(nx, ny);
                }
            }
            ans++;
        }
        return -1;
    }
};