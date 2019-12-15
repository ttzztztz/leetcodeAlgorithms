class Solution {
public:
    int N, M;
    bool pointValid(int x, int y) {
        return x >= 0 && y >= 0 && x < N && y < M;
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        N = grid.size(), M = grid[0].size();
        vector<vector<vector<bool>>> visited(N + 5, vector<vector<bool>>(M + 5, vector<bool>(k + 5, false)));

        deque<tuple<int, int, int, int>> queue;
        queue.emplace_back(0, 0, 0, k);

        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};

        while (!queue.empty()) {
            auto top = queue.front();
            queue.pop_front();

            int x, y, dist, remain;
            tie(x, y, dist, remain) = top;

            if (x == N - 1 && y == M - 1) {
                return dist;
            }

            for (int i = 0; i < 4; i++) {
                const int nx = x + dx[i], ny = y + dy[i];

                if (pointValid(nx, ny)) {
                    if (grid[nx][ny] == 0 && !visited[nx][ny][remain]) {
                        visited[nx][ny][remain] = true;
                        queue.emplace_back(nx, ny, dist + 1, remain);
                    } else if (grid[nx][ny] == 1 && remain - 1 >= 0 && !visited[nx][ny][remain - 1]) {
                        visited[nx][ny][remain - 1] = true;
                        queue.emplace_back(nx, ny, dist + 1, remain - 1);
                    }
                }
            }
        }

        return -1;
    }
};