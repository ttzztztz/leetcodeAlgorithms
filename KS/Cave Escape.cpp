#include <iostream>
#include <cstring>
#include <queue>

//#define DEBUG 1

using namespace std;

const int MAX = 105, MAXSTATE = (1 << 15) + 5, OBSTACLE = -100000;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

int E, map[MAX][MAX], trap[MAX][MAX], energy[MAXSTATE], adjacent[MAXSTATE];
int N = 0, M = 0, startX = 0, startY = 0, targetX = 0, targetY = 0;
long long dp[MAXSTATE];
bool visited[MAX][MAX], canReach[MAXSTATE];
vector<pair<int, int>> trapList;

bool pointValid(int x, int y) {
    return x >= 1 && y >= 1 && x <= N && y <= M && map[x][y] != OBSTACLE;
}

void bfs(int state) {
    energy[state] = E;
    memset(visited, 0, sizeof(visited));
    deque<pair<int, int>> queue;

    queue.emplace_back(startX, startY);
    visited[startX][startY] = true;

    for (int i = 0; i < trapList.size(); i++) {
        if (!(state & (1 << i))) {
            visited[trapList[i].first][trapList[i].second] = true;
        }
    }

    while (!queue.empty()) {
        const pair<int, int> point = queue.front();
        queue.pop_front();
        const int x = point.first, y = point.second;

        if (x == targetX && y == targetY) {
            canReach[state] = true;
        }
        for (int i = 0; i < 4; i++) {
            int nextX = x + dx[i], nextY = y + dy[i];
            if (!pointValid(nextX, nextY)) {
                continue;
            }

            if (!visited[nextX][nextY]) {
                visited[nextX][nextY] = true;
                energy[state] += map[nextX][nextY];
                queue.emplace_back(nextX, nextY);
            } else if (visited[nextX][nextY] && map[nextX][nextY] < 0) {
                adjacent[state] |= (1 << trap[nextX][nextY]);
            }
        }
    }
    adjacent[state] ^= state;
}

long long dfs(int state) {
    if (dp[state] != -2) {
        return dp[state];
    }

    long long answer = -1;
    if (canReach[state]) {
        answer = energy[state];
    }

    for (int i = 0; i < trapList.size(); i++) {
        if ((state & (1 << i)) == 0 && adjacent[state] & (1 << i) && energy[state] + map[trapList[i].first][trapList[i].second] >= 0) {
            answer = std::max(answer, dfs(state | (1 << i)));
        }
    }

    return dp[state] = answer;
}

void init() {
    N = M = startX = startY = targetX = targetY = 0;
    trapList.clear();

    memset(map, 0, sizeof(map));
    memset(trap, 0xff, sizeof(trap));
    memset(energy, 0, sizeof(energy));
    memset(adjacent, 0, sizeof(adjacent));
    memset(canReach, 0, sizeof(canReach));
    for (int i = 0; i < MAXSTATE; i++) {
        dp[i] = -2;
    }
}

int main() {
    int dataCount = 0;
    cin >> dataCount;
    for (int _ = 1; _ <= dataCount; _++) {
        init();
        // <-- input
        cin >> N >> M >> E >> startX >> startY >> targetX >> targetY;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                cin >> map[i][j];
                if (map[i][j] != OBSTACLE && map[i][j] < 0) {
                    trap[i][j] = trapList.size();
                    trapList.emplace_back(i, j);
                }
            }
        }
        // <-- bfs
        for (int state = 0; state <= (1 << trapList.size()); state++) {
            bfs(state);
        }
        // <-- dfs get answer
        printf("Case #%d: %lld \n", _, dfs(0));
    }

    return 0;
}
