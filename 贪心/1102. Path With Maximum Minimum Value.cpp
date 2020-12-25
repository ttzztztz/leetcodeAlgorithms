class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        if (A.empty()) return 0;
        const int n = A.size(), m = A[0].size();
        
        typedef tuple<int, int, int> State;
        priority_queue<State, vector<State>, less<>> q;
        q.emplace(A[0][0], 0, 0);
        auto point_valid = [&](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < n && j < m;
        };
        
        vector<vector<int>> dist(n, vector<int>(m, -1));
        dist[0][0] = A[0][0];
        
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        while (!q.empty()) {
            auto [min_val, i, j] = q.top();
            q.pop();
            
            if (i == n - 1 && j == m - 1) return min_val;
            for (int k = 0; k < 4; k++) {
                const int nx = i + dx[k], ny = j + dy[k];
                if (!point_valid(nx, ny)) continue;

                const int nval = min(A[nx][ny], min_val);
                if (nval > dist[nx][ny]) {
                    dist[nx][ny] = nval;
                    q.emplace(nval, nx, ny);
                }
            }
        }
        
        return -1; // never reach this branch
    }
};

