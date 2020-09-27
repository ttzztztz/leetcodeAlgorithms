#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

int s;
bool visited[64][64];

vector<int> dx0 = {0, 0, -1};
vector<int> dy0 = {1, -1, -1};
vector<int> dx1 = {0, 0, 1};
vector<int> dy1 = {1, -1, 1};

bool pointValid(int i, int j) {
    return i >= 1 && j >= 1 && i <= s && j <= 2 * i - 1;
}

void init() {
    memset(visited, 0, sizeof visited);
}

bool isEnd(int xa, int ya, int xb, int yb) {
    vector<int> dx, dy;
    if (ya % 2 == 1) dx = dx1, dy = dy1;
    else dx = dx0, dy = dy0;

    bool go1 = false, go2 = false;
    for (int k = 0; k < 3; k++) {
        const int nx = xa + dx[k], ny = ya + dy[k];
        if (!pointValid(nx, ny) || visited[nx][ny]) continue;

        go1 = true;
        break;
    }

    if (yb % 2 == 1) dx = dx1, dy = dy1;
    else dx = dx0, dy = dy0;
    for (int k = 0; k < 3; k++) {
        const int nx = xb + dx[k], ny = yb + dy[k];
        if (!pointValid(nx, ny) || visited[nx][ny]) continue;

        go2 = true;
        break;
    }

    return !go1 && !go2;
}

int dfs(int xa, int ya, int xb, int yb, int p1, int p2, int turn) {
    int tmp;
    if (isEnd(xa, ya, xb, yb)) return p1 - p2;

    if (turn == 0) { // Alice
        tmp = -9999999;
        vector<int> dx, dy;
        if (ya % 2 == 1) dx = dx1, dy = dy1;
        else dx = dx0, dy = dy0;

        bool go = false;
        for (int k = 0; k < 3; k++) {
            const int nx = xa + dx[k], ny = ya + dy[k];
            if (!pointValid(nx, ny) || visited[nx][ny]) continue;

            go = true;
            visited[nx][ny] = true;
            tmp = max(tmp, dfs(nx, ny, xb, yb, p1 + 1, p2, turn ^ 1));
            visited[nx][ny] = false;
        }

        if (!go) tmp = max(tmp, dfs(xa, ya, xb, yb, p1, p2, turn ^ 1));
    } else {
        tmp = 9999999;
        vector<int> dx, dy;
        if (yb % 2 == 1) dx = dx1, dy = dy1;
        else dx = dx0, dy = dy0;

        bool go = false;
        for (int k = 0; k < 3; k++) {
            const int nx = xb + dx[k], ny = yb + dy[k];
            if (!pointValid(nx, ny) || visited[nx][ny]) continue;

            go = true;
            visited[nx][ny] = true;
            tmp = min(tmp, dfs(xa, ya, nx, ny, p1, p2 + 1, turn ^ 1));
            visited[nx][ny] = false;
        }

        if (!go) tmp = min(tmp, dfs(xa, ya, xb, yb, p1, p2, turn ^ 1));
    }

    return tmp;
}

int main() {
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; _++) {
        long long answer = 0;
        init();

        int xa, xb, ya, yb, c;
        cin >> s >> xa >> ya >> xb >> yb >> c;
        for (int i = 0; i < c; i++) {
            int x, y;
            cin >> x >> y;
            visited[x][y] = true;
        }

        visited[xa][ya] = true;
        visited[xb][yb] = true;

        answer = dfs(xa, ya, xb, yb, 0, 0, 0);
        printf("Case #%d: %lld\n", _, answer);
    }
    return 0;
}
