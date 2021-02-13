class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        const int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        typedef pair<int, int> PII;
        
        if (grid[0][0] == 1) return -1;
        deque<PII> q = { {0, 0} };
        
        const int dx[] = {0, 0, -1, 1, -1, -1, 1, 1};
        const int dy[] = {-1, 1, 0, 0, -1, 1, -1, 1};
        
        auto point_valid = [&](int x, int y) -> bool {
            return x >= 0 && y >= 0 && x < n && y < n;
        };

        int len = 1;
        while (!q.empty()) {
            const int cnt = q.size();
            for (int _ = 0; _ < cnt; _++) {
                auto [x, y] = q.front();
                q.pop_front();
                if (x == n - 1 && y == n - 1) return len;
                visited[x][y] = true;
                
                for (int k = 0; k < 8; k++) {
                    const int nx = x + dx[k], ny = y + dy[k];
                    if (!point_valid(nx, ny) || visited[nx][ny] || grid[nx][ny] == 1) continue;
                    q.emplace_back(nx, ny);
                    visited[nx][ny] = true;
                }
            }
            len++;
        }
        return -1;
    }
};
