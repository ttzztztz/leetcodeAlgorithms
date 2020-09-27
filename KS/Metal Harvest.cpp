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
        long long answer = 0;
        long long n, k;
        cin >> n >> k;

        typedef pair<int, int> PII;
        vector<PII> all(n);
        for (int i = 0; i < n; i++) {
            cin >> all[i].first >> all[i].second;
        }
        sort(all.begin(), all.end());

        for (long long i = 0, last = -1; i < n; i++) {
            long long l, r;
            tie(l, r) = all[i];

            if (last <= l) {
                answer++;
                last = l + k;
            }

            if (last < r) {
                const long long rest = r - last;
                long long add = 0;
                add += rest / k;
                if (rest % k != 0) add++;

                answer += add;
                last = last + k * add;
            }
        }

        printf("Case #%d: %lld\n", _, answer);
    }
    return 0;
}
