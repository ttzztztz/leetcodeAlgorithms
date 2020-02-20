class Solution {
public:
    /**
     * @param grid: 
     * @return: The lowest number of moves to acquire all keys
     */
    int N, M;
    bool pointValid(int i, int j) {
        return i >= 0 && j >= 0 && i < N && j < M;
    }
    int shortestPathAllKeys(vector<string> &grid) {
        int startX = 0, startY = 0, keyCount = 0;
        N = grid.size(), M = grid[0].size();
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == '@') {
                    startX = i, startY = j;
                } else if (grid[i][j] >= 'a' && grid[i][j] <= 'f') {
                    keyCount++;
                }
            }
        }
        
        const int mask = (1 << keyCount) - 1;
        vector<vector<vector<bool>>> visited(mask + 5, vector<vector<bool>>(N + 5, vector<bool>(M + 5, false)));
        deque<tuple<int, int, int>> q;
        int answer = 0;
        q.emplace_back(startX, startY, 0);
        
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {1, -1, 0, 0};
        
        while (!q.empty()) {
            const int Q = q.size();
            for (int _ = 0; _ < Q; _++) {
                int x, y, state;
                tie(x, y, state) = q.front();
                visited[state][x][y] = true;
                q.pop_front();
                
                for (int k = 0; k < 4; k++) {
                    const int nx = x + dx[k], ny = y + dy[k];
                    int ns = state;
                    
                    if (!pointValid(nx, ny) || grid[nx][ny] == '#' || visited[ns][nx][ny]) continue;
                    if (grid[nx][ny] >= 'a' && grid[nx][ny] <= 'f') ns |= (1 << (grid[nx][ny] - 'a'));
                    if (grid[nx][ny] >= 'A' && grid[nx][ny] <= 'F' && !(state & (1 << (grid[nx][ny] - 'A')))) continue;
                    
                    if (ns == mask) return answer + 1;
                    visited[ns][nx][ny] = true;
                    q.emplace_back(nx, ny, ns);
                }
            }
            answer++;
        }
        
        return -1;
    }
};
