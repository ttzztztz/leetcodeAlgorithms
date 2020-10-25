class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int l = 0, r = 0;
        this->heights = heights;
        const int n = heights.size(), m = heights[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                r = max(r, heights[i][j]);
            }
        }
        
        while (l <= r) {
            const int mid = (l + r) >> 1;
            
            if (solve(mid)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return l;
    }
private:
    vector<vector<int>> heights;
    bool pointValid(int i, int j) {
        const int n = heights.size(), m = heights[0].size();
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    bool solve(int diff) {
        const int n = heights.size(), m = heights[0].size();
        typedef pair<int, int> Point;
        bool visited[105][105];
        memset(visited, 0, sizeof visited);
        
        deque<Point> q = { { 0, 0 } };
        
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        while (!q.empty()) {
            int x, y;
            tie(x, y) = q.front();
            q.pop_front();
            visited[x][y] = true;
            if (x == n - 1 && y == m - 1) return true;
            
            for (int k = 0; k < 4; k++) {
                const int nx = x + dx[k], ny = y + dy[k];
                if (pointValid(nx, ny) && !visited[nx][ny] && abs(heights[nx][ny] - heights[x][y]) <= diff) {
                    visited[nx][ny] = true;
                    q.emplace_back(nx, ny);
                }
            }
        }
        
        return false;
    }
};
