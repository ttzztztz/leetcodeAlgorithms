#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> B;
vector<vector<long long>> dp;
vector<vector<int>> edge;
int V;

void init() {
    B.clear();
    dp.clear();
    edge.clear();
}

void dfs(int u, int parent) {
    bool isLeaf = true;
    for (int v : edge[u]) {
        if (parent == v) continue;
        dfs(v, u);
        isLeaf = false;
    }

    if (isLeaf) {
        dp[u][0] = 0;
        dp[u][1] = B[u];
        dp[u][2] = -9999999;
        return;
    }

    dp[u][0] = 0;
    dp[u][1] = dp[u][2] = B[u];

    bool haveSolution = false;
    long long delta = -9999999;
    for (int v : edge[u]) {
        if (parent == v) continue;

        dp[u][0] += max(dp[v][0], dp[v][2]);
        dp[u][1] += max(
                dp[v][1],
                max(dp[v][0] + B[v], dp[v][2]));

        if (dp[v][1] >= max(dp[v][0], dp[v][2])) {
            haveSolution = true;
        } else {
            delta = max(delta, dp[v][1] - max(dp[v][0], dp[v][2]));
        }

        dp[u][2] += max(max(dp[v][0], dp[v][2]), dp[v][1]);
    }

    if (!haveSolution) {
        dp[u][2] += delta;
    }
}

int main() {
    int T = 0;
    cin >> T;

    for (int _ = 1; _ <= T; _++) {
        init();
        cin >> V;

        B = vector<int>(V + 5, 0);
        dp = vector<vector<long long>>(V + 5, vector<long long>(3, 0));
        edge = vector<vector<int>>(V + 5, vector<int>{});

        for (int i = 1; i <= V; i++) {
            int b = 0;
            cin >> b;
            B[i] = b;
        }

        for (int i = 0; i < V - 1; i++) {
            int x, y;
            cin >> x >> y;

            edge[x].push_back(y);
            edge[y].push_back(x);
        }

        dfs(1, 0);
        printf("Case #%d: %lld\n", _, max(max(dp[1][0], dp[1][1]), dp[1][2]));
    }
    return 0;
}