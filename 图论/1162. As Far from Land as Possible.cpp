class Solution {
public:
    int N, M;
    bool pointValid(int i, int j) {
        return i >= 0 && j >= 0 && i < N && j < M;
    }
    int maxDistance(vector<vector<int>>& grid) {
        N = grid.size(), M = grid[0].size();

        deque<pair<int, int>> queue;
        vector<vector<bool>> visited(N, vector<bool>(M, false));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == 1) {
                    queue.emplace_back(i, j);
                    visited[i][j] = true;
                }
            }
        }

        const int dx[] = {-1, 1, 0, 0};
        const int dy[] = {0, 0, -1, 1};

        int answer = -1;
        if (queue.size() == N * M) {
            return answer;
        }

        while (!queue.empty()) {
            answer++;

            for (int layerCount = queue.size(); layerCount > 0; layerCount--) {
                const pair<int, int> top = queue.front();
                queue.pop_front();

                for (int k = 0; k < 4; k++) {
                    const int nextX = top.first + dx[k], nextY = top.second + dy[k];
                    if (pointValid(nextX, nextY) && !visited[nextX][nextY] && grid[nextX][nextY] == 0) {
                        queue.emplace_back(nextX, nextY);
                        visited[nextX][nextY] = true;
                    }
                }
            }
        }

        return answer;
    }
};