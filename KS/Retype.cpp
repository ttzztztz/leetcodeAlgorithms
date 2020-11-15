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

int main() {
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; _++) {
        ll n, k, s, answer = 0;
        cin >> n >> k >> s;

        ll tmp = k - 1;
        answer = tmp + min(
                n + 1,
                k - s + n - s + 1);

        printf("Case #%d: %lld\n", _, answer);
    }
    return 0;
}
