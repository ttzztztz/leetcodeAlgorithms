class Solution {
public:
    /**
     * @param grid: the input matrix
     * @return: the new matrix
     */
    vector<vector<int>> shortestPath(vector<vector<int>> &grid) {
        const int N = grid.size(), M = grid[0].size();
        vector<vector<int>> answer = grid;
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        
        deque<pair<int, int>> q;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == -1) {
                    visited[i][j] = true;
                } else if (grid[i][j] == 1) {
                    visited[i][j] = true;
                    q.emplace_back(i, j);
                }
            }
        }
        
        const int dx[] = {1, -1, 0, 0};
        const int dy[] = {0, 0, 1, -1};
        
        auto pointValid = [&](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < N && j < M;
        };
        
        while (!q.empty()) {
            vector<pair<int, int>> currentLayer;
            while (!q.empty()) {
                int x, y;
                tie(x, y) = q.front();
                q.pop_front();
                currentLayer.emplace_back(x, y);
                visited[x][y] = true;
            }
            
            for (int k = 0; k < 4; k++) {
                const int fill = k + 2;
                for (auto& p : currentLayer) {
                    int x, y;
                    tie(x, y) = p;
                    
                    const int nx = x + dx[k], ny = y + dy[k];
                    if (pointValid(nx, ny) && !visited[nx][ny] && answer[nx][ny] == 0) {
                        visited[nx][ny] = true;
                        answer[nx][ny] = fill;
                        q.emplace_back(nx, ny);
                    }
                }
            }
            
        }
        
        return answer;
    }
};
