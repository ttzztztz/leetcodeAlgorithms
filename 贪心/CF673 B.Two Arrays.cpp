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
typedef long long ll;

int main() {
    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        int n;
        ll T;
        cin >> n >> T;
        vector<ll> all(n, 0);
        vector<int> color(n, 0);
        for (int i = 0; i < n; i++) cin >> all[i];

        unordered_map<ll, vector<int>> app;
        for (int i = 0; i < n; i++) app[all[i]].push_back(i);

        for (int i = 0; i < n; i++) {
            const ll a = all[i];
            while (!app[T - a].empty()) {
                auto idx = app[T - a].back();
                app[T - a].pop_back();

                color[idx] = color[i] ^ 1;
            }
        }

        for (int i = 0; i < n; i++) {
            printf("%d", color[i]);
            if (i != n - 1) printf(" ");
            else printf("\n");
        }
    }
    return 0;
}
