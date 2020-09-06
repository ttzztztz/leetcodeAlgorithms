#include <iostream>
#include <cstring>

using namespace std;

long long dp[31][31][31][31][31];

int main() {
    int n;
    while ((cin >> n), n) {
        int s[5] = {0};
        for (int i = 0; i < n; i++) cin >> s[i];

        memset(dp, 0, sizeof(dp));
        dp[0][0][0][0][0] = 1;

        for (int a = 0; a <= s[0]; a++) {
            for (int b = 0; b <= min(s[1], a); b++) {
                for (int c = 0; c <= min(s[2], b); c++) {
                    for (int d = 0; d <= min(s[3], c); d++) {
                        for (int e = 0; e <= min(s[4], d); e++) {
                            long long &v = dp[a][b][c][d][e];

                            if (a >= 1 && a - 1 >= b) v += dp[a - 1][b][c][d][e];
                            if (b >= 1 && b - 1 >= c) v += dp[a][b - 1][c][d][e];
                            if (c >= 1 && c - 1 >= d) v += dp[a][b][c - 1][d][e];
                            if (d >= 1 && d - 1 >= e) v += dp[a][b][c][d - 1][e];
                            if (e >= 1) v += dp[a][b][c][d][e - 1];
                        }
                    }
                }
            }
        }

        cout << dp[s[0]][s[1]][s[2]][s[3]][s[4]] << endl;
    }
    return 0;
}
