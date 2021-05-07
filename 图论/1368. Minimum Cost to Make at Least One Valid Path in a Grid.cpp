class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        const int n = grid.size(), m = grid[0].size();
        
        typedef tuple<int, int, int> State;
        priority_queue<State, vector<State>, greater<>> heap;
        heap.emplace(0, 0, 0);
        
        vector<vector<int>> dist(n, vector<int>(m, n * m + 5));
        const int dx[] = { 0, 0, 1, -1 };
        const int dy[] = { 1, -1, 0, 0 };
        
        auto point_valid = [&](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < n && j < m;
        };
        while (!heap.empty()) {
            auto [change, x, y] = heap.top();
            heap.pop();
            
            dist[x][y] = change;
            if (x == n - 1 && y == m - 1) return change;
            
            const int t = grid[x][y];
            for (int k = 1; k <= 4; k++) {
                const int nx = x + dx[k - 1], ny = y + dy[k - 1];
                if (point_valid(nx, ny) && change + (k != t) < dist[nx][ny]) {
                    dist[nx][ny] = change + (k != t);
                    heap.emplace(change + (k != t), nx, ny);
                }
            }
        }
        return n + m;
    }
};