class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        const int n = grid.size();
        int l = 0, r = (n * n) - 1;
        while (l <= r) {
            const int mid = (l + r) >> 1;
            if (solve(grid, mid)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
private:
    bool solve(const vector<vector<int>>& grid, int max_height) {
        const int n = grid.size();
        typedef pair<int, int> PII;
        if (grid[0][0] > max_height) return false;
        deque<PII> q = {{0, 0}};
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        
        auto point_valid = [&](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < n && j < n;
        };
        
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop_front();
            
            visited[x][y] = true;
            if (x == n - 1 && y == n - 1) return true;
            
            for (int k = 0; k < 4; k++) {
                const int nx = x + dx[k], ny = y + dy[k];
                if (!point_valid(nx, ny) || visited[nx][ny] || grid[nx][ny] > max_height) continue;
                
                q.emplace_back(nx, ny);
                visited[nx][ny] = true;
            }
        }
        
        return false;
    }
};
