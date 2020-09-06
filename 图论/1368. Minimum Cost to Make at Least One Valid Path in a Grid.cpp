const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

class Solution {
public:
    int N, M;
    typedef tuple<int, int, int> Point;
    bool pointValid(int i, int j) {
        return i >= 0 && j >= 0 && i < N && j < M;
    }
    int minCost(vector<vector<int>>& grid) {
        N = grid.size(), M = grid[0].size();

        priority_queue<Point, vector<Point>, greater<>> heap;
        heap.emplace(0, 0, 0);
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        
        while (!heap.empty()) {
            int dist, i, j;
            tie(dist, i, j) = heap.top();
            
            if (i == N - 1 && j == M - 1) return dist;
            heap.pop();
            if (visited[i][j]) continue;
            visited[i][j] = true;
            
            const int k = grid[i][j] - 1;
            if (pointValid(i + dx[k], j + dy[k])) heap.emplace(dist, i + dx[k], j + dy[k]);
            for (int s = 0; s < 4; s++) {
                if (s == k) continue;
                if (pointValid(i + dx[s], j + dy[s])) heap.emplace(dist + 1, i + dx[s], j + dy[s]);
            }
        }
        
        return -1;
    }
};
