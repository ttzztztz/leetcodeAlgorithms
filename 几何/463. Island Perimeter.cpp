class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int answer = 0;
        if (grid.empty()) return 0;
        const int N = grid.size(), M = grid[0].size();
        
        auto pointValid = [&](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < N && j < M;
        };
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == 0) continue;
                answer += 4;
                
                for (int k = 0; k < 4; k++) {
                    const int nx = i + dx[k], ny = j + dy[k];
                    if (pointValid(nx, ny) && grid[nx][ny] == 1) answer--;
                }
            }
        }
        return answer;
    }
};
