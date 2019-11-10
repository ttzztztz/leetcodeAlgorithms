class Solution {
public:
    int N, M;
    bool pointValid(int x, int y) {
        return x >= 0 && y >= 0 && x < N && y < M;
    }
    void dfs(vector<vector<bool>>& visited, vector<vector<int>>& grid, int x, int y, int target) {
        visited[x][y] = true;
        const int dx[] = {1, -1, 0, 0};
        const int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            const int nextX = x + dx[i], nextY = y + dy[i];

            if (pointValid(nextX, nextY) && !visited[nextX][nextY] && grid[nextX][nextY] == target) {
                dfs(visited, grid, nextX, nextY, target);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        N = grid.size(), M = grid[0].size();
        vector<vector<bool>> visited(N, vector<bool>(M, false));

        int answer = 0;

        // <-- dfs edge
        for (int i = 0; i < N; i++) {
            if (!visited[i][0] && grid[i][0] == 0) {
                dfs(visited, grid, i, 0, 0);
            }
            if (!visited[i][M - 1] && grid[i][M - 1] == 0) {
                dfs(visited, grid, i, M - 1, 0);
            }
        }
        for (int i = 0; i < M; i++) {
            if (!visited[0][i] && grid[0][i] == 0) {
                dfs(visited, grid, 0, i, 0);
            }
            if (!visited[N - 1][i] && grid[N - 1][i] == 0) {
                dfs(visited, grid, N - 1, i, 0);
            }
        }

        // <-- count answer
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j ++) {
                if (!visited[i][j] && grid[i][j] == 0) {
                    dfs(visited, grid, i, j, 0);
                    answer++;
                }
            }
        }

        return answer;
    }
};