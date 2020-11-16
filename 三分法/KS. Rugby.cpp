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

        ll ans = 0, mi = numeric_limits<ll>::max();
        sort(all_x.begin(), all_x.end());
        sort(all_y.begin(), all_y.end());

        ll l = -2e9, r = 2e9;
        auto dist = [&](ll start) -> ll {
            ll ans = 0;
            for (int i = 0; i < n; i++) {
                ans += abs(start + i - all_x[i]);
            }
            return ans;
        };

        while (l <= r) {
            const ll margin = (r - l) / 3;
            const ll ml = l + margin, mr = r - margin;

            const ll sl = dist(ml), sr = dist(mr);
            mi = min(mi, min(sl, sr));
            if (sl <= sr) {
                r = mr - 1;
            }
            if (sr <= sl) {
                l = ml + 1;
            }
        }

        const ll mid_y = all_y[n / 2];
        for (ll i : all_y) ans += abs(i - mid_y);

        printf("Case #%d: %lld\n", _, ans + mi);
    }
    return 0;
}
