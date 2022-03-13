class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        const int n = heights.size(), m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, numeric_limits<int>::max()));
        
        typedef tuple<int, int, int> State;
        priority_queue<State, vector<State>, greater<>> heap;
        heap.emplace(0, 0, 0);
        dist[0][0] = 0;
        
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        
        auto point_valid = [&](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < n && j < m;
        };
        
        while (!heap.empty()) {
            auto [d, x, y] = heap.top();
            heap.pop();
            if (d != dist[x][y]) continue;
            
            if (x == n - 1 && y == m - 1) return d;
            dist[x][y] = min(dist[x][y], d);
            
            for (int k = 0; k < 4; k++) {
                const int nx = x + dx[k], ny = y + dy[k];
                if (!point_valid(nx, ny)) continue;
                
                const int cost = abs(heights[x][y] - heights[nx][ny]);
                if (max(cost, dist[x][y]) < dist[nx][ny]) {
                    dist[nx][ny] = max(cost, dist[x][y]);
                    heap.emplace(max(cost, dist[x][y]), nx, ny);
                }
            }
        }
        
        return 0; // never reach
    }
};
