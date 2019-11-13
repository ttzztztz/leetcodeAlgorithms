class Solution {
public:
    int startX, startY, endX, endY, N, M, noObstacleCount;
    bool pointValid(const vector<vector<int>>& grid, int x, int y) {
        return x >= 0 && y >= 0 && x < N && y < M && grid[x][y] != -1;
    }
    int dfs(const vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int count) {
        if (grid[x][y] == 2) {
            return (count == noObstacleCount + 1) ? 1 : 0;
        }

        const int dx[] = {1, -1, 0, 0};
        const int dy[] = {0, 0, -1, 1};

        int answer = 0;
        for (int i = 0; i < 4; i++) {
            const int nextX = x + dx[i], nextY = y + dy[i];

            if (pointValid(grid, nextX, nextY) && !visited[nextX][nextY]) {
                visited[nextX][nextY] = true;
                answer += dfs(grid, visited, nextX, nextY, count + 1);
                visited[nextX][nextY] = false;
            }
        }
        return answer;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        N = grid.size(), M = grid[0].size(), noObstacleCount = 0;

        vector<vector<bool>> visited(N + 5, vector<bool>(M + 5, false));
        // find the start & end
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == 1) {
                    startX = i, startY = j;
                } else if (grid[i][j] == 2) {
                    endX = i, endY = j;
                } else if (grid[i][j] == 0) {
                    noObstacleCount++;
                }
            }
        }

        // dfs
        visited[startX][startY] = true;
        return dfs(grid, visited, startX, startY, 0);
    }
};