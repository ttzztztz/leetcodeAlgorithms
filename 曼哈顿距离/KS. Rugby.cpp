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

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

int main() {
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; _++) {
        int n;
        cin >> n;
        vector<ll> all_x, all_y;
        for (int i = 0; i < n; i++) {
            ll x, y;
            cin >> x >> y;

            all_x.push_back(x), all_y.push_back(y);
        }

        ll ans = 0;
        sort(all_x.begin(), all_x.end());
        sort(all_y.begin(), all_y.end());

        for (int i = 0; i < n; i++) all_x[i] -= i;
        sort(all_x.begin(), all_x.end());
        const ll mid_x = all_x[n / 2];
        for (ll i : all_x) ans += abs(i - mid_x);

        const ll mid_y = all_y[n / 2];
        for (ll i : all_y) ans += abs(i - mid_y);

        printf("Case #%d: %lld\n", _, ans);
    }
    return 0;
}
