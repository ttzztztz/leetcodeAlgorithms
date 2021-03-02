class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        const int n = grid.size(), m = grid[0].size();
        typedef pair<int, int> PII;
        
        deque<PII> q;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            bool find = false;
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '*') {
                    find = true;
                    q.emplace_back(i, j);
                    visited[i][j] = true;
                    break;
                }
            }
        }
        
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        auto point_valid = [&](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < n && j < m;
        };
        
        int dist = 0;
        while (!q.empty()) {
            const int cnt = q.size();
            for (int _ = 0; _ < cnt; _++) {
                auto [x, y] = q.front();
                q.pop_front();
                
                if (grid[x][y] == '#') return dist;
                for (int k = 0; k < 4; k++) {
                    const int nx = x + dx[k], ny = y + dy[k];
                    if (!point_valid(nx, ny) || visited[nx][ny] || grid[nx][ny] == 'X') continue;
                    
                    if (grid[nx][ny] == '#') return dist + 1;
                    visited[nx][ny] = true;
                    q.emplace_back(nx, ny);
                }
                
            }
            dist++;
        }
        return -1;
    }
};
