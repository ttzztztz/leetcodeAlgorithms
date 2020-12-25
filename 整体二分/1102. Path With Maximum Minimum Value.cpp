class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        if (A.empty()) return 0;
        grid_ = A;
        n_ = A.size(), m_ = A[0].size();
        
        int l = numeric_limits<int>::max(), r = numeric_limits<int>::min();
        for (auto& i : A) {
            for (auto& j : i) {
                l = min(l, j);
                r = max(r, j);
            }
        }
        
        while (l <= r) {
            const int mid = (l + r) / 2;
            if (judge(mid)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        return r;
    }
private:
    vector<vector<int>> grid_;
    int n_, m_;
    
    bool point_valid(int i, int j) {
        return i >= 0 && j >= 0 && i < n_ && j < m_;
    }
    
    bool judge(int min_val) {
        vector<vector<bool>> visited(n_, vector<bool>(m_, false));

        if (grid_[0][0] < min_val) return false;
        deque<pair<int, int>> q = { {0, 0} };
        
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop_front();
            visited[i][j] = true;
            if (i == n_ - 1 && j == m_ - 1) return true;
            
            for (int k = 0; k < 4; k++) {
                const int nx = i + dx[k], ny = j + dy[k];
                if (!point_valid(nx, ny) || visited[nx][ny] || grid_[nx][ny] < min_val) continue;
                
                q.emplace_back(nx, ny);
                visited[nx][ny] = true;
            }
        }
        return false;
    }
};
