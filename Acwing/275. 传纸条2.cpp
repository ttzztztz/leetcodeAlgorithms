#include <iostream>

using namespace std;

int N, M;
int graph[55][55], dp[110][55][55];

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 2; i <= N + M - 1; i++) {
        for (int j = 1; j <= N; j++) {
            const int m = i - j;
            for (int k = j + 1; k <= N; k++) {
                const int n = i - k;

                if (m < 1 || n < 1) continue;
                dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k]);
                dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1]);
                dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
                dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k - 1]);

                dp[i][j][k] += graph[j][m] + graph[k][n];
            }
        }
    }

    cout << dp[N + M - 1][N - 1][N];
    return 0;
}
