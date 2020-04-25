class Solution {
public:
    /**
     * @param mazeMap: a 2D grid
     * @return: return the minium distance
     */
    int getMinDistance(vector<vector<int>> &mazeMap) {
        if (mazeMap.empty()) return 0;
        
        typedef pair<int, int> Point;
        const int N = mazeMap.size(), M = mazeMap[0].size();
        
        auto pointValid = [&](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < N && j < M;
        };
        
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        unordered_map<int, vector<Point>> allSame;
        unordered_map<int, bool> cntVisited;
        
        int startX = -1, endX = -1;
        int startY = -1, endY = -1;
        
        int answer = 0;
        deque<Point> q;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (mazeMap[i][j] == -1) continue;
                else if (mazeMap[i][j] == -2) {
                    startX = i, startY = j;
                    q.emplace_back(i, j);
                    visited[i][j] = true;
                } else if (mazeMap[i][j] == -3) {
                    endX = i, endY = j;
                } else if (mazeMap[i][j] > 0) {
                    allSame[mazeMap[i][j]].emplace_back(i, j);
                }
            }
        }
        
        const int dx[] = {-1, 1, 0, 0};
        const int dy[] = {0, 0, -1, 1};
        
        while (!q.empty()) {
            int cnt = q.size();
            for (int _ = 0; _ < cnt; _++) {
                int i, j;
                tie(i, j) = q.front();
                q.pop_front();
                
                if (i == endX && j == endY) return answer;
                visited[i][j] = true;
                
                for (int k = 0; k < 4; k++) {
                    const int nx = i + dx[k], ny = j + dy[k];
                    
                    if (!pointValid(nx, ny) || visited[nx][ny] || mazeMap[nx][ny] == -1) continue;
                    
                    visited[nx][ny] = true;
                    if (nx == endX && ny == endY) return answer + 1;
                    q.emplace_back(nx, ny);
                }
                
                if (mazeMap[i][j] > 0 && cntVisited[mazeMap[i][j]]) continue;
                if (mazeMap[i][j] > 0) cntVisited[mazeMap[i][j]] = true;
                
                for (auto& k : allSame[mazeMap[i][j]]) {
                    int nx, ny;
                    tie(nx, ny) = k;
                    
                    if (!pointValid(nx, ny) || visited[nx][ny] || mazeMap[nx][ny] == -1) continue;
                    
                    visited[nx][ny] = true;
                    q.emplace_back(nx, ny);
                }
            }
            answer++;
        }
        
        return -1;
    }
};
