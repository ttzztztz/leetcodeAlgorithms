class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        const int n = grid.size(), m = grid[0].size();
        
        typedef tuple<int, int, int> State;
        priority_queue<State, vector<State>, greater<>> heap;
        vector<vector<int>> dist(n, vector<int>(m, numeric_limits<int>::max() / 2));
        
        dist[0][0] = grid[0][0];
        heap.emplace(grid[0][0], 0, 0);
        
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        
        auto point_valid = [&](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < n && j < m;
        };
        
        while (!heap.empty()) {
            auto [h, x, y] = heap.top();
            if (h != dist[x][y]) continue;
            heap.pop();
            
            if (x == n - 1 && y == m - 1) return h;
            for (int k = 0; k < 4; k++) {
                const int nx = x + dx[k], ny = y + dy[k];
                if (point_valid(nx, ny) && dist[nx][ny] > max(h, grid[nx][ny])) {
                    dist[nx][ny] = max(h, grid[nx][ny]);
                    heap.emplace(dist[nx][ny], nx, ny);
                }
            }
        }
        return -1; // never
    }
};