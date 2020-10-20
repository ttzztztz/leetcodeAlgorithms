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

typedef pair<int, int> PII;
vector<vector<PII>> edges;
vector<double> f;
vector<bool> visited;

void dfs(int u) {
    if (visited[u]) return;

    visited[u] = true;
    const int deg = edges[u].size();
    for (auto [v, w] : edges[u]) {
        dfs(v);
        f[u] += 1.0 * (f[v] + w) / deg;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    edges = vector<vector<PII>>(n + 1, vector<PII>{});
    f = vector<double>(n + 1, 0.0);
    visited = vector<bool>(n + 1, false);

    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        edges[x].emplace_back(y, w);
    }

    dfs(1);
    printf("%.2lf\n", f[1]);
    return 0;
}
