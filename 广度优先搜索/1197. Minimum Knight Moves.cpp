class Solution {
public:
    int minKnightMoves(int x, int y) {
        deque<Point> q = { {0, 0} };
        const int maxn = 605;
        vector<vector<bool>> visited(maxn * 2, vector<bool>(maxn * 2, false));
        visited[0 + maxn][0 + maxn] = true;
        int len = 0;

        const int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
        const int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
        while (!q.empty()) {
            const int cnt = q.size();
            for (int _ = 0; _ < cnt; _++) {
                auto [i, j] = q.front();
                q.pop_front();
    
                if (i == x && j == y) return len;

                for (int k = 0; k < 8; k++) {
                    const int nx = i + dx[k], ny = j + dy[k];

                    if (visited[nx + maxn][ny + maxn]) continue;
                    visited[nx + maxn][ny + maxn] = true;

                    if (nx == x && ny == y) return len + 1;
                    q.emplace_back(nx, ny);
                }
            }
            len++;
        }
        return -1;
    }
private:
    typedef pair<int, int> Point;
};