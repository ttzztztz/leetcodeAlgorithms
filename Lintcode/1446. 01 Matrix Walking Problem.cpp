class Solution {
public:
    /**
     * @param grid: The gird
     * @return: Return the steps you need at least
     */
    typedef pair<int, int> Point;
    typedef tuple<int, int, bool> State;
    int getBestRoad(vector<vector<int>> &grid) {
        const int N = grid.size(), M = grid[0].size();
        
        deque<State> queue;
        if (grid[0][0] == 0) queue.emplace_back(0, 0, false);
        else queue.emplace_back(0, 0, true);
        vector<vector<vector<bool>>> visited(N, vector<vector<bool>>(M, vector<bool>(2, false)));
        
        const int dx[] = {0, 0, 1, -1};
        const int dy[] = {-1, 1, 0, 0};
        
        auto pointValid = [&](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < N && j < M;
        };
        
        int answer = 0;
        while (!queue.empty()) {
            int cnt = queue.size();
            
            for (int _ = 0; _ < cnt; _++) {
                int x, y;
                bool step;
                tie(x, y, step) = queue.front();
                queue.pop_front();
                
                if (x == N - 1 && y == M - 1) return answer;
                visited[x][y][step] = true;
                
                for (int k = 0; k < 4; k++) {
                    const int nx = x + dx[k], ny = y + dy[k];
                    if (!pointValid(nx, ny)) continue;
                    
                    if (grid[nx][ny] == 1 && step) continue;
                    
                    if (grid[nx][ny] == 1 && !step) {
                        if (visited[nx][ny][1]) continue;
                        queue.emplace_back(nx, ny, true);
                        visited[nx][ny][1] = true;
                    } else if (grid[nx][ny] == 0) {
                        if (visited[nx][ny][step]) continue;
                        queue.emplace_back(nx, ny, step);
                        visited[nx][ny][step] = true;
                    }
                }
            }
            answer++;
        }
        
        return -1;
    }
};
