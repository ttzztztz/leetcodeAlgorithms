class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.empty()) return;
        const int n = rooms.size(), m = rooms[0].size();
        deque<pair<int, int>> q;
        auto point_valid = [&](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < n && j < m;
        };
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (rooms[i][j] == 0) q.emplace_back(i, j);
            }
        }
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        const int kInfinity = numeric_limits<int>::max();
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        
        int dist = 0;
        while (!q.empty()) {
            const int cnt = q.size();
            for (int _ = 0; _ < cnt; _++) {
                auto [i, j] = q.front();
                q.pop_front();
                visited[i][j] = true;
                if (rooms[i][j] == kInfinity) {
                    rooms[i][j] = dist;
                }
                
                for (int k = 0; k < 4; k++) {
                    const int nx = i + dx[k], ny = j + dy[k];
                    if (point_valid(nx, ny) && !visited[nx][ny] && rooms[nx][ny] == kInfinity) {
                        q.emplace_back(nx, ny);
                        visited[nx][ny] = true;
                    }
                }
            }
            dist++;
        }
    }
};
