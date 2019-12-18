class Solution {
public:
    int N, M;
    bool pointValid(int i, int j) {
        return i >= 0 && j >= 0 && i < N && j < M;
    }
    void dfs(vector<vector<int>>& grid, const vector<vector<int>>& originalGrid, vector<vector<bool>>& visited, int x, int y, const int color, const int startColor) {
        visited[x][y] = true;

        const int dx[] = {-1, 1, 0, 0};
        const int dy[] = {0, 0, -1, 1};

        int adjacentCount = 0;
        for (int i = 0; i < 4; i++) {
            const int nextX = x + dx[i], nextY = y + dy[i];

            if (!pointValid(nextX, nextY) || originalGrid[nextX][nextY] != startColor) {
                adjacentCount++;
            }

            if (pointValid(nextX, nextY) && grid[nextX][nextY] == startColor && !visited[nextX][nextY]) {
                dfs(grid, originalGrid, visited, nextX, nextY, color, startColor);
            }
        }

        if (adjacentCount != 0) {
            grid[x][y] = color;
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        N = grid.size(), M = grid[0].size();
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        vector<vector<int>> newGrid = grid;

        const int startColor = grid[r0][c0];
        dfs(newGrid, grid, visited, r0, c0, color, startColor);
        return newGrid;
    }
};