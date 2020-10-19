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
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; _++) {
        int n;
        cin >> n;

        vector<long long> all(n, 0);
        for (int i = 0; i < n; i++) cin >> all[i];

        vector<vector<long double>> f(n, vector<long double>(n, 0.0));
        vector<long long> pref = {0};
        vector<double> a(n, 0.0), b(n, 0.0);

        for (long long i : all) pref.push_back(pref.back() + i);

        for (int i = 0; i < n; i++) f[i][i] = 0;
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                const int j = i + len - 1;

                long long sum = pref[j + 1] - pref[i];
                f[i][j] = 1.0 * sum + (1.0 * (a[i] + b[j]) / (len - 1));
                a[i] += f[i][j];
                b[j] += f[i][j];
            }
        }


        printf("Case #%d: %Lf\n", _, f[0][n - 1]);
    }
    return 0;
}
