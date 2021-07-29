class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        if (mat.empty()) return {};
        const int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        typedef pair<int, int> PII;
        deque<PII> q;
        
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            if (mat[i][j] == 0) {
                visited[i][j] = true;
                q.emplace_back(i, j);
            }
        }
        
        const int dx[] = { 0, 0, -1, 1 };
        const int dy[] = { -1, 1, 0, 0 };
        
        auto point_valid = [&](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < n && j < m;
        };

        int dist = 0;
        while (!q.empty()) {
            const int cnt = q.size();
            for (int _ = 0; _ < cnt; _++) {
                auto [x, y] = q.front();
                q.pop_front();
                
                ans[x][y] = dist;
                visited[x][y] = true;
                
                for (int k = 0; k < 4; k++) {
                    const int nx = x + dx[k], ny = y + dy[k];
                    if (point_valid(nx, ny) && !visited[nx][ny]) {
                        visited[nx][ny] = true;
                        q.emplace_back(nx, ny);
                    }
                }
            }
            dist++;
        }
        
        return ans;
    }
};
