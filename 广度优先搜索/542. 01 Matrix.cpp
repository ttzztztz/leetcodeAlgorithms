class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        const int N = matrix.size(), M = matrix[0].size();
        vector<vector<int>> answer(N, vector<int>(M, 9999999));
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        
        typedef pair<int, int> PII;
        deque<PII> q;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (matrix[i][j] == 0) {
                    answer[i][j] = 0;
                    q.emplace_back(i, j);
                    visited[i][j] = true;
                }
            }
        }
        
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {1, -1, 0, 0};
        
        auto pointValid = [&](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < N && j < M;
        };
        
        int d = 0;
        while (!q.empty()) {
            const int cnt = q.size();
            for (int _ = 0; _ < cnt; _++) {
                int i, j;
                tie(i, j) = q.front();
                q.pop_front();
                
                if (d < answer[i][j]) answer[i][j] = d;
                
                for (int k = 0; k < 4; k++) {
                    const int nx = i + dx[k], ny = j + dy[k];
                    if (pointValid(nx, ny) && !visited[nx][ny]) {
                        visited[nx][ny] = true;
                        q.emplace_back(nx, ny);
                    }
                }
            }
            d++;
        }
        
        return answer;
    }
};