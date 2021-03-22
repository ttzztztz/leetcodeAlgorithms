#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

int main() {
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; _++) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n + 5, vector<int>(m + 5, 0));
        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> arr[i][j];
        ll ans = 0;
        vector<vector<vector<int>>> f(n + 5, vector<vector<int>>(m + 5, vector<int>(4, 0)));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (arr[i][j]) {
                    f[i][j][0] = f[i - 1][j][0] + 1;
                    f[i][j][1] = f[i][j - 1][1] + 1;
                }
            }
            for (int j = m; j >= 1; j--) {
                if (arr[i][j]) {
                    f[i][j][2] = f[i][j + 1][2] + 1;
                }
            }
        }
        for (int i = n; i >= 1; i--) {
            for (int j = 1; j <= m; j++) {
                if (arr[i][j]) {
                    f[i][j][3] = f[i + 1][j][3] + 1;
                }
            }
        }

        vector<PII> dir = {
                {0, 1},
                {0, 2},
                {3, 1},
                {3, 2}
        };
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (arr[i][j] == 0) continue;

                for (auto[a, b] : dir) {
                    const int l = min(f[i][j][a], f[i][j][b]);
                    const int r = max(f[i][j][a], f[i][j][b]);

                    ans += max(0, min(l, r / 2) - 1);
                    ans += max(0, min(l / 2, r) - 1);
                }

            }
        }

        printf("Case #%d: %lld\n", _, ans);
    }
    return 0;
}

