#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 6005;

int dp[MAX][2], happy[MAX], parent[MAX];
vector<int> graph[MAX];

void dfs(int u) {
    dp[u][1] = happy[u];
    for (int v : graph[u]) {
        dfs(v);

        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}

int main() {
    int N, root = 0;
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> happy[i];
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;

        parent[u] = v;
        graph[v].push_back(u);
    }

    for (int j = 1; j <= N; j++) {
        if (parent[j] == 0) {
            root = j;
            break;
        }
    }

    dfs(root);
    cout << max(dp[root][0], dp[root][1]) << endl;
    return 0;
}