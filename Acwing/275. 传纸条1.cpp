#include <iostream>

using namespace std;

int N, M;
int graph[55][55], dp[55][55][55][55];

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            for (int k = i + 1; k <= N; k++) {
                for (int m = 1; m <= M; m++) {
                    dp[i][j][k][m] = max(dp[i][j][k][m], dp[i - 1][j][k][m - 1]);
                    dp[i][j][k][m] = max(dp[i][j][k][m], dp[i][j - 1][k][m - 1]);
                    dp[i][j][k][m] = max(dp[i][j][k][m], dp[i - 1][j][k - 1][m]);
                    dp[i][j][k][m] = max(dp[i][j][k][m], dp[i][j - 1][k - 1][m]);

                    dp[i][j][k][m] += graph[i][j] + graph[k][m];
                }
            }
        }
    }

    cout << dp[N - 1][M][N][M - 1];
    return 0;
}
