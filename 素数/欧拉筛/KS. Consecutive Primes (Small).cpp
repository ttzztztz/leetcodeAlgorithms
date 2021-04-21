#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

int prime[10000005];
int check[10000005];
int pos = 0;

void shai(int N) {
  check[0] = check[1] = 0;
  for (int i = 2; i <= N; i++) {
    if (!check[i]) {
      prime[pos++] = i;
    }

    for (int j = 0; j < pos && i * prime[j] <= N; j++) {
      check[i * prime[j]] = 1;

      if (i % prime[j] == 0) {
        break;
      }
    }
  }
}

int main() {
  // freopen("./in.txt", "r", stdin);
  int T;
  cin >> T;
  shai(1e7);
  for (int _ = 1; _ <= T; _++) {
    ll ans = 0;
    ll n;
    cin >> n;

    for (int i = 0; i + 1 < pos; i++) {
      if (1ll * prime[i] * prime[i + 1] <= n) {
        ans = 1ll * prime[i] * prime[i + 1];
      }
    }
    printf("Case #%d: %lld\n", _, ans);
  }
  return 0;
}
