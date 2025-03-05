/**
 * // This is the GridMaster's API interface.
 * // You should not implement it, or speculate about its implementation
 * class GridMaster {
 *   public:
 *     bool canMove(char direction);
 *     void move(char direction);
 *     boolean isTarget();
 * };
 */

class Solution {
public:
    int findShortestPath(GridMaster &master) {
        m = vector<vector<int>>(1005, vector<int>(1005, -1));
        m[sx][sy] = cell;
        dfs(master, sx, sy);
        return bfs();
    }
private:
    vector<vector<int>> m;

    const int cell = 0;
    const int target = 1;
    const int sx = 501, sy = 501;

    void dfs(GridMaster &master, int i, int j) {
        if (master.isTarget()) {
            m[i][j] = target;
        }

        const char dir[] = {'U', 'D', 'L', 'R'};
        const char dir_rev[] = {'D', 'U', 'R', 'L'};
        const int dx[] = {0, 0, 1, -1};
        const int dy[] = {1, -1, 0, 0};

        for (int k = 0; k < 4; k++) {
            const int nx = i + dx[k], ny = j + dy[k];
            if (m[nx][ny] == -1 && master.canMove(dir[k])) {
                master.move(dir[k]);
                m[nx][ny] = cell;
                dfs(master, nx, ny);
                master.move(dir_rev[k]);
            }
        }
    }

    int bfs() {
        const int dx[] = {0, 0, 1, -1};
        const int dy[] = {1, -1, 0, 0};

        int len = 0;
        deque<pair<int, int>> q = { {sx, sy} };
        unordered_set<string> visited = { "0,0" };

        while (!q.empty()) {
            const int cnt = q.size();
            for (int i = 0; i < cnt; i++) {
                auto[x, y] = q.front();
                q.pop_front();

                if (m[x][y] == target) return len;
                for (int k = 0; k < 4; k++) {
                    const int nx = x + dx[k], ny = y + dy[k];
                    const string h = hash(nx, ny);
    
                    if (m[nx][ny] != -1 && !visited.count(h)) {
                        if (m[nx][ny] == target) return len + 1;
                        visited.insert(h);
                        q.emplace_back(nx, ny);
                    }
                }
            }
            len++;
        }
        return -1;
    }

    string hash(int x, int y) {
        return to_string(x) + "," + to_string(y);
    }
};