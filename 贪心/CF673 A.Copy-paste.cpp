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
    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        int n, k;
        cin >> n >> k;
        vector<int> all(n, 0);
        for (int i = 0; i < n; i++) cin >> all[i];

        int ans = 0;
        sort(all.begin(), all.end());
        for (int i = 1; i < n; i++) {
            ans += max(0, (k - all[i]) / all[0]);
        }

        cout << ans << endl;
    }
    return 0;
}
