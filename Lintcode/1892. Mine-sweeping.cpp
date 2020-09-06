class Solution {
public:
    /**
     * @param Mine_map: an array represents the map.
     * @param Start: the start position.
     * @return: return an array including all reachable positions.
     */
    vector<vector<int>> Mine_sweeping(vector<vector<int>> &mine, vector<int> &start) {
        vector<vector<int>> answer;
        const int N = mine.size(), M = mine[0].size();
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        typedef pair<int, int> PII;
        
        deque<PII> q;
        visited[start[0]][start[1]] = true;
        q.emplace_back(start[0], start[1]);
        answer.push_back(vector<int>{start[0], start[1]});
        
        auto pointValid = [&](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < N && j < M;
        };
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        
        while (!q.empty()) {
            int x, y;
            tie(x, y) = q.front();
            q.pop_front();
            
            if (mine[x][y] == 0) continue;
            for (int k = 0; k < 4; k++) {
                const int nx = x + dx[k], ny = y + dy[k];
                if (!pointValid(nx, ny) || visited[nx][ny]) continue;
                
                visited[nx][ny] = true;
                q.emplace_back(nx, ny);
                answer.push_back(vector<int>{nx, ny});
            }
        }
        
        return answer;
    }
};
