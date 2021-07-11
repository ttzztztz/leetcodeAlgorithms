class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        const int n = maze.size(), m = maze[0].size();
        
        auto point_valid = [&](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < n && j < m;
        };
        
        typedef pair<int, int> PII;
        deque<PII> q = { {entrance[0], entrance[1]} };
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        const int dx[] = { -1, 1, 0, 0 };
        const int dy[] = { 0, 0, -1, 1 };
        
        int dist = 0;
        while (!q.empty()) {
            const int cnt = q.size();
            for (int _ = 0; _ < cnt; _++) {
                auto [x, y] = q.front();
                q.pop_front();
                visited[x][y] = true;
                
                for (int k = 0; k < 4; k++) {
                    const int nx = x + dx[k], ny = y + dy[k];
                    if (!point_valid(nx, ny) && !(x == entrance[0] && y == entrance[1])) return dist;
                    
                    if (point_valid(nx, ny) && !visited[nx][ny] && maze[nx][ny] == '.') {
                        visited[nx][ny] = true;
                        q.emplace_back(nx, ny);
                    }
                }
            }
            dist++;
        }
        return -1;
    }
};