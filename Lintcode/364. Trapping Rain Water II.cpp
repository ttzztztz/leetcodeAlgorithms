class Solution {
public:
    /**
     * @param heights: a matrix of integers
     * @return: an integer
     */
    int N, M;
    bool pointValid(int i, int j) {
        return i >= 0 && j >= 0 && i < N && j < M;
    }
    typedef tuple<int, int, int> Point;
    int trapRainWater(vector<vector<int>> &heights) {
        priority_queue<Point, vector<Point>, greater<>> heap;
        
        int answer = 0;
        N = heights.size(), M = heights[0].size();
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        for (int i = 0; i < N; i++) {
            heap.emplace(heights[i][0], i, 0);
            heap.emplace(heights[i][M - 1], i, M - 1);
            visited[i][0] = visited[i][M - 1] = true;
        }
        for (int i = 1; i < M - 1; i++) {
            heap.emplace(heights[0][i], 0, i);
            heap.emplace(heights[N - 1][i], N - 1, i);
            visited[0][i] = visited[N - 1][i] = true;
        }
        
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        while (!heap.empty()) {
            int h, x, y;
            tie(h, x, y) = heap.top();
            heap.pop();
            
            for (int i = 0; i < 4; i++) {
                const int nx = x + dx[i], ny = y + dy[i];
                if (!pointValid(nx, ny) || visited[nx][ny]) continue;
                visited[nx][ny] = true;
                answer += max(0, h - heights[nx][ny]);
                heap.emplace(max(h, heights[nx][ny]), nx, ny);
            }
        }
        
        return answer;
    }
};
