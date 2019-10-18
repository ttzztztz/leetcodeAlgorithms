class QueueItem {
public:
    int x, y, layer, state;
    QueueItem() : x(0), y(0), layer(0), state(0) {};
    QueueItem(int _x, int _y, int _l, int _s) : x(_x), y(_y), layer(_l), state(_s) {};
};

class Solution {
public:
    int n, m;
    bool pointValid(int x, int y) {
        return x >= 0 && y >= 0 && x < n && y < m;
    }
    int shortestPathAllKeys(vector<string>& grid) {
        int startX = 0, startY = 0, keyCount = 0;
        this->n = grid.size(), this->m = grid[0].size();

        const int dx[] = {1, -1, 0, 0};
        const int dy[] = {0, 0, -1, 1};

        bool visited[35][35][72];
        std::memset(visited, 0, sizeof(visited));

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '@') {
                    startX = i, startY = j;
                } else if (grid[i][j] >= 'a' && grid[i][j] <= 'f') {
                    keyCount++;
                }
            }
        }

        const int finishState = (1 << keyCount) - 1;
        deque<QueueItem> queue;
        queue.push_back(QueueItem(startX, startY, 0, 0));
        visited[startX][startY][0] = true;
        while (!queue.empty()) {
            const QueueItem item = queue.front();
            queue.pop_front();

            if (item.state == finishState) {
                return item.layer;
            }

            for (int i = 0; i < 4; i++) {
                const int nextX = item.x + dx[i], nextY = item.y + dy[i], state = item.state, layer = item.layer;

                if (pointValid(nextX, nextY) && grid[nextX][nextY] != '#' && !visited[nextX][nextY][state]) {
                    visited[nextX][nextY][state] = true;

                    if (grid[nextX][nextY] >= 'a' && grid[nextX][nextY] <= 'f') {
                        queue.push_back(QueueItem(nextX, nextY, layer + 1, state | (1 << (grid[nextX][nextY] - 'a'))));
                    } else if (grid[nextX][nextY] >= 'A' && grid[nextX][nextY] <= 'F') {
                        if (state & (1 << (grid[nextX][nextY] - 'A'))) {
                            queue.push_back(QueueItem(nextX, nextY, layer + 1, state));
                        }
                    } else if (grid[nextX][nextY] == '.' || grid[nextX][nextY] == '@') {
                        queue.push_back(QueueItem(nextX, nextY, layer + 1, state));
                    }

                }
            }
        }

        return -1;
    }
};