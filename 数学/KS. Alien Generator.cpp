#include <algorithm>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstring>
using namespace std;

typedef long long ll;
const ll maxn = 5e6 + 5;

int main() {
  // freopen("./in.txt", "r", stdin);
  int T;
  cin >> T;

  for (int _ = 1; _ <= T; _++) {
    ll g;
    cin >> g;
    ll ans = 0;
    for (ll n = 1; n <= maxn; n++) {
      const ll t = (2 * g / n) - n + 1;
      if ((2 * g) % n == 0 && t % 2 == 0 && t >= 2) {
        ans++;
      }
    }

    printf("Case #%d: %lld\n", _, ans);
  }
  return 0;
}
