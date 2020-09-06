class Solution {
public:
    /**
     * @param matrix : the martix
     * @return: the distance of grid to the police
     */
    typedef pair<int, int> Point;
    vector<vector<int>> policeDistance(vector<vector<int>> &matrix) {
        const int N = matrix.size(), M = matrix[0].size();
        
        vector<vector<int>> answer(N, vector<int>(M));
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        
        deque<Point> q;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (matrix[i][j] == -1) {
                    answer[i][j] = -1;
                    visited[i][j] = true;
                } else if (matrix[i][j] == 1) {
                    visited[i][j] = true;
                    q.emplace_back(i, j);
                }
            }
        }
        
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        auto pointValid = [&](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < N && j < M;
        };
        
        int dist = 0;
        while (!q.empty()) {
            int cnt = q.size();
            for (int _ = 0; _ < cnt; _++) {
                int x, y;
                tie(x, y) = q.front();
                q.pop_front();
                
                visited[x][y] = true;
                for (int k = 0; k < 4; k++) {
                    const int nx = x + dx[k], ny = y + dy[k];
                    if (!pointValid(nx, ny) || visited[nx][ny] ||  matrix[nx][ny] != 0) continue;
                    
                    answer[nx][ny] = dist + 1;
                    visited[nx][ny] = true;
                    q.emplace_back(nx, ny);
                }
            }
            dist++;
        }
        
        return answer;
    }
};
