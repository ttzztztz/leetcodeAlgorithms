#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

int main() {
  // freopen("./in.txt", "r", stdin);
  int T;
  cin >> T;
  for (int _ = 1; _ <= T; _++) {
    ll ans = 2;
    int n;
    cin >> n;
    vector<ll> num(n), g(n, 0), f(n, 0);
    for (int i = 0; i < n; i++) cin >> num[i];

    f[0] = 1;
    f[1] = 2;
    for (int i = 2; i < n; i++) {
      if (num[i] - num[i - 1] == num[i - 1] - num[i - 2]) {
        f[i] = f[i - 1] + 1;
      } else {
        f[i] = 2;
      }
      ans = max(ans, f[i]);
    }

    g[n - 1] = 1;
    g[n - 2] = 2;
    for (int i = n - 3; i >= 0; i--) {
      if (num[i] - num[i + 1] == num[i + 1] - num[i + 2]) {
        g[i] = g[i + 1] + 1;
      } else {
        g[i] = 2;
      }
      ans = max(ans, g[i]);
    }

    for (int i = 0; i < n; i++) {
      if (i + 1 < n) ans = max(ans, g[i + 1] + 1);
      if (i - 1 >= 0) ans = max(ans, f[i - 1] + 1);

      if (i + 2 < n && i - 2 >= 0 &&
          num[i + 2] - num[i + 1] == num[i - 1] - num[i - 2] &&
          num[i + 1] - num[i - 1] == 2 * (num[i - 1] - num[i - 2])) {
        ans = max(ans, g[i + 1] + f[i - 1] + 1);
      }

      if (i + 2 < n && i - 1 >= 0 && num[i + 1] - num[i - 1] == 2 * (num[i + 2] - num[i + 1])) {
        ans = max(ans, g[i + 1] + 2);
      }

      if (i - 2 >= 0 && i + 1 < n && num[i + 1] - num[i - 1] == 2 * (num[i - 1] - num[i - 2])) {
        ans = max(ans, f[i - 1] + 2);
      }

      if (i - 1 >= 0 && i + 1 < n) ans = max(ans, 3ll);
    }

    if (n <= 3) ans = n;
    printf("Case #%d: %lld\n", _, ans);
  }
  return 0;
}
