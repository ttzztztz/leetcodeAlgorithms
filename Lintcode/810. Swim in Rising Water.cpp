class Solution {
public:
    /**
     * @param grid: the grid
     * @return: the least time you can reach the bottom right square
     */
    typedef pair<int, int> Point;
    int N;
    bool pointValid(int i, int j) {
        return i >= 0 && j >= 0 && i < N && j < N;
    }
    bool judge(const vector<vector<int>> &grid, int K) {
        if (grid[0][0] > K) return false;
        
        vector<vector<bool>> visited(N, vector<bool>(N, false));
        visited[0][0] = true;
        
        deque<Point> q;
        q.emplace_back(0, 0);
        
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        
        while (!q.empty()) {
            int x, y;
            tie(x, y) = q.front();
            
            visited[x][y] = true;
            if (x == N - 1 && y == N - 1) return true;
            q.pop_front();
            
            for (int k = 0; k < 4; k++) {
                const int nx = x + dx[k], ny = y + dy[k];
                if (!pointValid(nx, ny) || visited[nx][ny] || grid[nx][ny] > K) continue;
                
                visited[nx][ny] = true;
                if (nx == N - 1 && ny == N - 1) return true;
                
                q.emplace_back(nx, ny);
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>> &grid) {
        N = grid.size();
        
        int left = 0, right = N * N - 1;
        while (left <= right) {
            const int mid = (left + right) >> 1;
            if (judge(grid, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
