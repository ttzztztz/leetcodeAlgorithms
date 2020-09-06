class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        const int N = image.size(), M = image[0].size();
        
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        visited[sr][sc] = true;
        const int color = image[sr][sc];
        
        const int dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};
        auto pointValid = [&](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < N && j < M;
        };
        
        typedef pair<int, int> PII;
        deque<PII> q = {{sr, sc}};
        while (!q.empty()) {
            int i, j;
            tie(i, j) = q.front();
            q.pop_front();
            
            visited[i][j] = true;
            image[i][j] = newColor;
            
            for (int k = 0; k < 4; k++) {
                const int nx = i + dx[k], ny = j + dy[k];
                if (!pointValid(nx, ny) || visited[nx][ny] || image[nx][ny] != color) continue;
                
                visited[nx][ny] = true;
                q.emplace_back(nx, ny);
            }
        }
        
        return image;
    }
};
