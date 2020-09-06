#include <iostream>
#include <vector>

using namespace std;

const int MAX = 305;
vector<int> graph[MAX];
int N, M;
int score[MAX], parent[MAX];
int dp[MAX][MAX];

void dfs(int u) {
    for (int v : graph[u]) {
        dfs(v);

        for (int j = M - 1; j >= 0; j--) {
            for (int k = 0; k <= j; k++) {
                dp[u][j] = max(dp[v][k] + dp[u][j - k], dp[u][j]);
            }
        }
    }

    for (int j = M; j >= 1; j--) {
        dp[u][j] = dp[u][j - 1] + score[u];
    }
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> parent[i] >> score[i];

        graph[parent[i]].push_back(i);
    }
    M++;

    dfs(0);
    cout << dp[0][M] << endl;
    return 0;
}
