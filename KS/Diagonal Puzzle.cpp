#include <iostream>
#include <vector>

using namespace std;

int N, answer;
const int MAX = 105;

vector<vector<int>> graph;
vector<vector<int>> constraints;
vector<int> color, path;

void init() {
    answer = 0;
    graph = vector<vector<int>>(MAX * 4, vector<int>{});
    constraints = vector<vector<int>>(MAX * 4, vector<int>(MAX * 4));
    color = vector<int>(MAX * 4, -1);
    path.clear();
}

void dfs(int u, int col, int parent) {
    color[u] = col;
    path.push_back(u);

    for (int v : graph[u]) {
        if (color[v] != -1 || v == parent) continue;

        if (constraints[u][v] == 1) {
            dfs(v, col ^ 1, u);
        } else {
            dfs(v, col, u);
        }
    }
}

int main() {
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; _++) {
        init();
        cin >> N;

        for (int i = 0; i < N; i++) {
            string temp;
            cin >> temp;
            for (int j = 0; j < N; j++) {
                const int u = i + j, v = 3 * N - 2 - i + j;

                graph[u].push_back(v);
                graph[v].push_back(u);

                if (temp[j] == '.') { // white
                    constraints[u][v] = constraints[v][u] = 1; // diff
                } else {
                    constraints[u][v] = constraints[v][u] = 0; // same
                }
            }
        }

        for (int i = 0; i < 4 * N - 2; i++) {
            if (color[i] != -1) continue;

            dfs(i, 1, -1);
            int temp[2] = {0, 0};
            for (int u : path) {
                temp[color[u]]++;
            }
            answer += min(temp[0], temp[1]);

            path.clear();
        }
        printf("Case #%d: %d\n", _, answer);
    }
    return 0;
}