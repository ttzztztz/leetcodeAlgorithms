class Solution {
public:
    /**
     * @param side_length: the length of a side of the lake (it's a square)
     * @param lake_grid: a 2D matrix representing the lake 0= ice, 1= snowbank, -1= hole 
     * @param albert_row: row of Albert's snowbank
     * @param albert_column: column of Albert's snowbank 
     * @param kuna_row: row of Kuna's snowbank 
     * @param kuna_column: column of Kuna's snowbank
     * @return: a bool - whether Albert can escape
     */
    bool lakeEscape(int side_length, vector<vector<int>> &lake_grid, int albert_row, int albert_column, int kuna_row, int kuna_column) {
        dogX = kuna_row, dogY = kuna_column;
        N = side_length;
        memset(visited, 0, sizeof visited);
        return dfs(albert_row, albert_column, 0, lake_grid);
    }
private:
    bool visited[15][15][2];
    int dogX, dogY;
    int N;
    bool pointValid(int i, int j) {
        return i >= 0 && j >= 0 && i < N && j < N;
    }
    bool dfs(int i, int j, int state, vector<vector<int>> &grid) {
        if (i == dogX && j == dogY) state = 1;
        if (visited[i][j][state]) return false;
        visited[i][j][state] = true;
        const int dx[] = {1, -1, 0, 0};
        const int dy[] = {0, 0, 1, -1};
        
        for (int k = 0; k < 4; k++) {
            const int nx = i + dx[k], ny = j + dy[k];
            if (!pointValid(nx, ny) && state == 1) return true; 
            if (pointValid(nx, ny) && !visited[nx][ny][state]) {
                if (grid[nx][ny] == -1) continue;
                else if (grid[nx][ny] == 0) {
                    int tx = nx, ty = ny;
                    while (pointValid(tx, ty)) {
                        if (grid[tx][ty] == -1) break;
                        else if (grid[tx][ty] == 1) {
                            if (dfs(tx, ty, state, grid)) return true;
                            break;
                        }
                        tx += dx[k], ty += dy[k];
                    }
                    if (!pointValid(tx, ty) && state == 1) return true;
                } else {
                    if (dfs(nx, ny, state, grid)) return true;
                }
            }
        }
        return false;
    }
};
