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
        long long answer = numeric_limits<long long>::max();
        int w, n;
        cin >> w >> n;
        vector<long long> all(w, 0);
        for (int i = 0; i < w; i++) cin >> all[i];
        for (int i = 0; i < w; i++) all.push_back(all[i] + n);
        sort(all.begin(), all.end());

        long long cur = 0;
        for (int i = 0; i < w; i++) {
            const int mid = ((w - 1) / 2);
            cur += abs(all[mid] - all[i]);
        }

        answer = cur;
        for (int i = 0; i < w; i++) {
            const int remove = i, add = i + w;

            if (w % 2 == 1) { // odd
                const int oldidx = i + (w - 1) / 2, newidx = oldidx + 1;
                cur -= all[oldidx] - all[remove];
                cur += all[add] - all[newidx];
            } else {
                const int oldidx = i + (w + 1) / 2, newidx = oldidx;
                cur -= all[oldidx] - all[remove];
                cur += all[add] - all[newidx];
            }

            answer = min(answer, cur);
        }

        printf("Case #%d: %lld\n", _, answer);
    }
    return 0;
}
