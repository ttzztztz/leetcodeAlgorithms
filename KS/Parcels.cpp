#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <limits.h>
#include <tuple>

using namespace std;

vector<vector<int>> graph;
int R, C;

bool pointValid(int x, int y) {
    return x >= 0 && y >= 0 && x < R && y < C;
}

const int dx[] = {0, 0, 1, -1};
const int dy[] = {-1, 1, 0, 0};

deque<pair<int, int>> queue;
vector<vector<bool>> visited;

bool check(int K) {
    queue.clear();
    visited = vector<vector<bool>>(R, vector<bool>(C, false));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (graph[i][j] == 1) {
                queue.emplace_back(i, j);
                visited[i][j] = true;
            }
        }
    }

    for (int i = 0; i <= K; i++) {
        int size = queue.size();
        for (int j = 0; j < size; j++) {
            int x, y;
            tie(x, y) = queue.front();
            visited[x][y] = true;
            queue.pop_front();

            if (i == K) continue;
            for (int k = 0; k < 4; k++) {
                const int nx = x + dx[k], ny = y + dy[k];

                if (pointValid(nx, ny) && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    queue.emplace_back(nx, ny);
                }
            }
        }
    }

    int xPyMax = INT_MIN, xPyMin = INT_MAX;
    int xMyMax = INT_MIN, xMyMin = INT_MAX;

    bool haveUnvisited = false;
    for (int x = 0; x < R; x++) {
        for (int y = 0; y < C; y++) {
            if (visited[x][y]) {
                continue;
            }

            haveUnvisited = true;
            xPyMax = max(xPyMax, x + y);
            xPyMin = min(xPyMin, x + y);

            xMyMax = max(xMyMax, x - y);
            xMyMin = min(xMyMin, x - y);
        }
    }

    for (int x = 0; x < R; x++) {
        for (int y = 0; y < C; y++) {
            if (graph[x][y] != 0) continue;

            if ((x + y) - xPyMin <= K && xPyMax - (x + y) <= K &&
                (x - y) - xMyMin <= K && xMyMax - (x - y) <= K) {
                return true;
            }
        }
    }
    return !haveUnvisited;
}

int main() {
    int T = 0;
    cin >> T;

    for (int _ = 1; _ <= T; _++) {
        cin >> R >> C;

        bool haveZero = false;
        graph = vector<vector<int>>(R, vector<int>(C, 0));
        for (int i = 0; i < R; i++) {
            char temp[255];
            cin >> temp;

            for (int j = 0; j < C; j++) {
                if (temp[j] == '0') haveZero = true;
                graph[i][j] = temp[j] - '0';
            }
        }

        if (!haveZero) {
            printf("Case #%d: %d\n", _, 0);
            continue;
        }

        int left = 0, right = R + C;
        while (left < right) {
            const int middle = (left + right) >> 1;

            if (check(middle)) {
                right = middle;
            } else {
                left = middle + 1;
            }
        }
        printf("Case #%d: %d\n", _, right);
    }
    return 0;
}