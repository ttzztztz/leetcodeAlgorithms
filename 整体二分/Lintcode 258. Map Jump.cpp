class Solution {
public:
    /**
     * @param arr: the map
     * @return:  the smallest target that satisfies from the upper left corner (0, 0) to the lower right corner (n-1, n-1)
     */
    int mapJump(vector<vector<int>> &arr) {
        N = arr.size();
        int left = 0, right = 1000;
        while (left <= right) {
            const int mid = (left + right) >> 1;
            if (reach(arr, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
private:
    int N;
    bool pointValid(int i, int j) {
        return i >= 0 && j >= 0 && i < N && j < N;
    }
    bool reach(const vector<vector<int>>& arr, int target) {
        vector<vector<bool>> visited(N, vector<bool>(N, false));
        typedef pair<int, int> PII;
        deque<PII> q = {{0,0}};
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        
        while (!q.empty()) {
            int i, j;
            tie(i, j) = q.front();
            q.pop_front();
            visited[i][j] = true;
            
            if (i == N - 1 && j == N - 1) return true;
            for (int k = 0; k < 4; k++) {
                const int nx = i + dx[k], ny = j + dy[k];
                
                if (pointValid(nx, ny) && !visited[nx][ny] && abs(arr[i][j] - arr[nx][ny]) <= target) {
                    visited[nx][ny] = true;
                    q.emplace_back(nx, ny);
                }
            }
        }
        return false;
    }
};
