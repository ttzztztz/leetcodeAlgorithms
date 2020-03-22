const vector<vector<int>> dx = {{0, 0}, {-1, 1}, {0, 1}, {0, 1}, {0, -1}, {0, -1}};
const vector<vector<int>> dy = {{-1, 1}, {0, 0}, {-1, 0}, {1, 0}, {-1, 0}, {1, 0}};

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        N = grid.size(), M = grid[0].size();
        visited = vector<vector<bool>>(N, vector<bool>(M, false));
        
        dfs(grid, 0, 0);
        
        return this->answer;
    }
private:
    int N, M;
    vector<vector<bool>> visited;
    bool pointValid(int i, int j) {
        return i >= 0 && j >= 0 && i < N && j < M;
    }
    bool answer = false;
    void dfs(const vector<vector<int>>& grid, int i, int j) {
        if (!pointValid(i, j)) return;
        if (answer) return;
        if (i == N - 1 && j == M - 1) {
            answer = true;
            return;
        }
        
        visited[i][j] = true;
        
        for (int k = 0; k < 2; k++) {
            const int nx = i + dx[grid[i][j] - 1][k], ny = j + dy[grid[i][j] - 1][k];
            if (!pointValid(nx, ny) || visited[nx][ny]) continue;
            
            bool canReach = false;
            for (int m = 0; m < 2; m++) {
                const int _x = nx + dx[grid[nx][ny] - 1][m], _y = ny + dy[grid[nx][ny] - 1][m];
                if (_x == i && _y == j) canReach = true;
            }
            if (!canReach) continue;
            
            visited[nx][ny] = true;
            dfs(grid, nx, ny);
        }
    }
};
