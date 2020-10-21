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

typedef long double ld;

int main() {
    int n;
    string str;

    cin >> n >> str;
    vector<ld> f(n + 1, 0.0);

    ld len = 0.0;
    for (int i = 1; i <= n; i++) {
        const char ch = str[i - 1];

        if (ch == 'o') {
            f[i] = f[i - 1] + 2 * len + 1;
            len += 1.0;
        } else if (ch == 'x') {
            len = 0.0;
            f[i] = f[i - 1];
        } else if (ch == '?') {
            f[i] = f[i - 1] + len + 0.5;
            len = (len + 1.0) / 2.0;
        }
    }

    printf("%.4Lf\n", f[n]);
    return 0;
}
