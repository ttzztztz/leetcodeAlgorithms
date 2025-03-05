class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        const int n = grid.size(), m = grid[0].size();
        int s_i, s_j;
        for (int i = 0; i < n; i++) {
            bool flag = false;
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    s_i = i, s_j = j;
                    flag = true;
                    break;
                }
            }

            if (flag) break;
        }

        typedef pair<int, int> Point;
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        auto point_valid = [&](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < n && j < m;
        };

        deque<Point> q = { { s_i, s_j } };
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop_front();

            grid[i][j] = 2;
            for (int k = 0; k < 4; k++) {
                const int ni = i + dx[k];
                const int nj = j + dy[k];

                if (!point_valid(ni, nj) || grid[ni][nj] != 1) continue;
                q.emplace_back(ni, nj);
                grid[ni][nj] = 2;
            }
        }

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            if (grid[i][j] == 2) {
                q.emplace_back(i, j);
                visited[i][j] = true;
            }
        }


        int ans = 0;
        while (!q.empty()) {
            const int cnt = q.size();
            for (int c = 0; c < cnt; c++) {
                auto [i, j] = q.front();
                q.pop_front();

                if (grid[i][j] == 1) return ans - 1;
                visited[i][j] = true;

                for (int k = 0; k < 4; k++) {
                    const int ni = i + dx[k];
                    const int nj = j + dy[k];

                    if (!point_valid(ni, nj) || visited[ni][nj]) continue;
                    visited[ni][nj] = true;
                    q.emplace_back(ni, nj);
                }
            }
            ans++;
        }

        return -1;
    }
};