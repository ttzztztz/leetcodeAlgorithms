class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int freshcnt = 0;
        const int N = grid.size(), M = grid[0].size();
        
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        typedef pair<int, int> PII;
        deque<PII> q;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == 1) freshcnt++;
                else if (grid[i][j] == 2) {
                    visited[i][j] = true;
                    q.emplace_back(i, j);
                }
            }
        }
        
        if (freshcnt == 0) return 0;
        int answer = 0;
        
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        
        auto pointValid = [&](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < N && j < M;
        };
        
        while (!q.empty()) {
            const int cnt = q.size();
            if (freshcnt == 0) return answer;
            for (int _ = 0; _ < cnt; _++) {
                int x, y;
                tie(x, y) = q.front();
                q.pop_front();
                
                for (int k = 0; k < 4; k++) {
                    const int nx = x + dx[k], ny = y + dy[k];
                    
                    if (pointValid(nx, ny) && !visited[nx][ny]) {
                        if (grid[nx][ny] == 1) {
                            visited[nx][ny] = true;
                            q.emplace_back(nx, ny);
                            freshcnt--;
                        }
                    }
                }
            }
            answer++;
        }
        
        
        
        return -1;
    }
};