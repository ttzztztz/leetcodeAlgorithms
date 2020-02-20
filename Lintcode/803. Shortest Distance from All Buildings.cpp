class Solution {
public:
    /**
     * @param grid: the 2D grid
     * @return: the shortest distance
     */
    typedef pair<int, int> Point;
    int N, M;
    bool pointValid(int x, int y) {
        return x >= 0 && y >= 0 && x < N && y < M;
    }
    int shortestDistance(vector<vector<int>> &grid) {
        map<Point, int> house;
        N = grid.size(), M = grid[0].size();
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] != 1) continue;
                const int n = house.size();
                house[{i, j}] = n;
            }
        }
        
        const int INF = 9999999, H = house.size();
        vector<vector<vector<int>>> dist(H + 1, vector<vector<int>>(N + 1, vector<int>(M + 1, INF)));
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {1, -1, 0, 0};
        
        for (auto& p : house) {
            int x, y;
            tie(x, y) = p.first;
            const int h = p.second;
            
            vector<vector<bool>> visited(N + 1, vector<bool>(M + 1, false));
            deque<Point> queue;
            queue.emplace_back(x, y);
            visited[x][y] = true;
            int cur = 0;
            while (!queue.empty()) {
                const int q = queue.size();
                for (int _ = 0; _ < q; _++) {
                    int i, j;
                    tie(i, j) = queue.front();
                    queue.pop_front();
                    dist[h][i][j] = cur;
                    
                    for (int k = 0; k < 4; k++) {
                        const int nx = i + dx[k], ny = j + dy[k];
                        if (!pointValid(nx, ny) || visited[nx][ny] || grid[nx][ny] != 0) continue;
                        queue.emplace_back(nx, ny);
                        visited[nx][ny] = true;
                    }
                }
                cur++;
            }
        }
        
        int answer = INF;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] != 0) continue;
                
                bool valid = true;
                int t = 0;
                for (int h = 0; h < H; h++) {
                    if (dist[h][i][j] >= INF) {
                        valid = false;
                        break;
                    }
                    t += dist[h][i][j];
                }
                if (!valid) continue;
                answer = min(answer ,t);
            }
        }
        
        if (answer >= INF) {
            return -1;
        } else {
            return answer;
        }
    }
};
