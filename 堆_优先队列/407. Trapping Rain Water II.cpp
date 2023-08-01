class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        const int n = heightMap.size();
        const int m = heightMap[0].size();

        int ans = 0, mx = 0;
        typedef tuple<int, int, int> State;

        priority_queue<State, vector<State>, greater<>> heap;
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        auto point_valid = [&](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < n && j < m;
        };

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            heap.emplace(heightMap[i][0], i, 0);
            heap.emplace(heightMap[i][m - 1], i, m - 1);
            visited[i][0] = visited[i][m - 1] = true;
        }
        for (int i = 1; i < m - 1; i++) {
            heap.emplace(heightMap[0][i], 0, i);
            heap.emplace(heightMap[n - 1][i], n - 1, i);
            visited[0][i] = visited[n - 1][i] = true;
        }

        while (!heap.empty()) {
            auto [h, i, j] = heap.top();
            heap.pop();

            mx = max(mx, h);
            ans += max(0, mx - h);
            for (int k = 0; k < 4; k++) {
                const int nx = i + dx[k], ny = j + dy[k];
                if (point_valid(nx, ny) && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    heap.emplace(heightMap[nx][ny], nx, ny);
                }
            }
        }
        return ans;
    }
};