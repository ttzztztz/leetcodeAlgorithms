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

int main() {
    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;

        vector<vector<int>> fly(n + 1, vector<int>{});
        vector<double> f(n + 1, 0.0);
        vector<bool> used(n + 1, false);

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            fly[v].push_back(u);
        }

        for (int i = n; i >= 0; i--) {
            if (!used[i] && i < n) {
                for (int k = 1; k <= 6 && i + k <= n; k++) {
                    const int u = i + k;
                    f[i] += f[u] / 6;
                }

                f[i] += 1;
            }

            for (int v : fly[i]) {
                f[v] = f[i];
                used[v] = true;
            }
        }

        printf("%.4lf\n", f[0]);
    }

    return 0;
}
