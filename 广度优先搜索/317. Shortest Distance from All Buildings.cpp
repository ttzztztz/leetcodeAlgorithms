class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        n_ = grid.size(), m_ = grid[0].size();
        grid_ = grid;
        dist_ = cnt_ = vector<vector<int>>(n_, vector<int>(m_, 0));
        
        int building_cnt = 0;
        for (int i = 0; i < n_; i++) {
            for (int j = 0; j < m_; j++) {
                if (grid[i][j] == 1) {
                    bfs(i, j);
                    building_cnt++;
                }
            }
        }
        
        int ans = -1;
        for (int i = 0; i < n_; i++) {
            for (int j = 0; j < m_; j++) {
                if (cnt_[i][j] == building_cnt) {
                    if (ans == -1 || dist_[i][j] < ans) {
                        ans = dist_[i][j];
                    }
                }
            }
        }
        return ans;
    }
private:
    vector<vector<int>> dist_, cnt_, grid_;
    int n_, m_;
    
    bool point_valid(int i, int j) {
        return i >= 0 && j >= 0 && i < n_ && j < m_;
    }
    
    void bfs(int i, int j) {
        deque<pair<int, int>> q = { {i, j} };
        vector<vector<bool>> visited(n_, vector<bool>(m_, false));
        
        int cur = 0;
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        while (!q.empty()) {
            const int cnt = q.size();
            for (int _ = 0; _ < cnt; _++) {
                auto [i, j] = q.front();
                q.pop_front();
                visited[i][j] = true;
                if (grid_[i][j] == 0) {
                    dist_[i][j] += cur;
                    cnt_[i][j]++;
                }
                
                for (int k = 0; k < 4; k++) {
                    const int nx = i + dx[k], ny = j + dy[k];
                    if (point_valid(nx, ny) && !visited[nx][ny] && grid_[nx][ny] == 0) {
                        visited[nx][ny] = true;
                        q.emplace_back(nx, ny);
                    }
                }
            }
            cur++;
        }
    }
};
