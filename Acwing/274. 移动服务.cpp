#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int w[205][205], q[1005], dp[1005][205][205];
int L, N;

int main() {
    cin >> L >> N;
    for (int i = 1; i <= L; i++) {
        for (int j = 1; j <= L; j++) {
            cin >> w[i][j];
        }
    }

    for (int i = 1; i <= N; i++) cin >> q[i];
    q[0] = 3;

    memset(dp, 0x3f, sizeof(dp));
    dp[0][1][2] = 0;

    for (int i = 0; i <= N - 1; i++) {
        const int n = q[i], c = q[i + 1];
        for (int j = 1; j <= L; j++) {
            for (int k = 1; k <= L; k++) {
                if (dp[i][j][k] >= 0x3f3f3f3f) continue;
                if (j == k || j == n || k == n) continue;

                dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k] + w[n][c]);
                dp[i + 1][j][n] = min(dp[i + 1][j][n], dp[i][j][k] + w[k][c]);
                dp[i + 1][n][k] = min(dp[i + 1][n][k], dp[i][j][k] + w[j][c]);
            }
        }
    }

    int answer = 0x3f3f3f3f;
    for (int i = 1; i <= L; i++) {
        for (int j = 1; j <= L; j++) {
            const int n = q[N];

            if (j == i || j == n || i == n) continue;
            answer = min(answer, dp[N][i][j]);
        }
    }

    cout << answer << endl;
    return 0;
}
