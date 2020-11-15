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
#include <tuple>
#include <cstring>

using namespace std;

typedef pair<int, int> PII;
typedef pair<double, double> PDD;
typedef long long ll;

ll f[20][20][2][2];
int digits[20];
int digitLen;

ll dfs(int length, int idx, int isZero, int isSmall) {
    if (length == 0) return 1;

    ll &val = f[length][idx][isZero][isSmall];
    if (val != -1) return val;

    ll answer = 0;
    if (idx == 0) {
        answer += dfs(
                length - 1,
                0,
                0,
                isSmall || 0 < digits[length]
        );
    }


    for (int i = 0; i <= 9; i++) {
        if (!isSmall && i > digits[length]) {
            break;
        }

        if ((idx % 2 == 1 && i % 2 == 0) || (idx % 2 == 0 && i % 2 == 1)) {
            answer += dfs(
                    length - 1,
                    (isZero && i == 0) ? 0 : (idx + 1),
                    isZero && i == 0,
                    isSmall || i < digits[length]
            );
        }
    }
    return val = answer;
}

ll solve(ll n) {
    digitLen = 0;
    memset(digits, 0, sizeof digits);
    memset(f, 0xff, sizeof f);

    ll t = n;
    while (t) {
        digits[++digitLen] = t % 10;
        t /= 10;
    }
    return dfs(digitLen, 0, 1, 0);
}

int main() {
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; _++) {
        ll l, r;
        cin >> l >> r;

        ll ans = solve(r) - solve(l - 1);
        printf("Case #%d: %lld\n", _, ans);
    }
    return 0;
}
