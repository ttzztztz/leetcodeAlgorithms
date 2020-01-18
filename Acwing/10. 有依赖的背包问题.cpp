#include <iostream>
#include <vector>

using namespace std;
int dp[105][105];
int volume[105], price[105], parent[105];
int N, V, root;
vector<vector<int>> graph;

void dfs(int u, int p) {
    for (int v : graph[u]) {
        if (v == p) continue;

        dfs(v, u);
        for (int j = V - volume[u]; j >= 0; j--) {
            for (int k = 0; k <= j; k++) {
                dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[v][k]);
            }
        }
    }

    for (int j = V; j >= 0; j--) {
        if (j >= volume[u]) {
            dp[u][j] = dp[u][j - volume[u]] + price[u];
        } else {
            dp[u][j] = 0;
        }
    }
}

int main() {
    cin >> N >> V;
    graph = vector<vector<int>>(N + 5, vector<int>{});
    for (int i = 1; i <= N; i++) {
        cin >> volume[i] >> price[i] >> parent[i];
        if (parent[i] == -1) {
            root = i;
        } else {
            graph[parent[i]].push_back(i);
            graph[i].push_back(parent[i]);
        }
    }

    dfs(root, -1);
    cout << dp[root][V] << endl;
    return 0;
}
