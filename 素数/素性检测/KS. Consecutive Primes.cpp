#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

int fast_pow(int a, int b, int mod) {
  int ans = 1, base = a;
  while (b) {
    if (b & 1) {
      ans = (1ll * ans * base) % mod;
    }

    base = (1ll * base * base) % mod;
    b >>= 1;
  }
  return ans;
}

bool miller_rabin(int n) {
  if (n < 2) return false;

  for (int p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29})
    if (n % p == 0) return n == p;

  int r = __builtin_ctz(n - 1);
  int d = (n - 1) >> r;

  for (int a : {2, 7, 61}) {
    int x = fast_pow(a % n, d, n);
    if (x <= 1 || x == n - 1) continue;
    for (int i = 0; i < r - 1 && x != n - 1; i++) x = 1LL * x * x % n;
    if (x != n - 1) return false;
  }

  return true;
}

int main() {
  // freopen("./in.txt", "r", stdin);
  int T;
  cin >> T;

  for (int _ = 1; _ <= T; _++) {
    ll n;
    cin >> n;
    ll ans = 0;
    int t = sqrt(n);

    int b = t;
    while (!miller_rabin(b)) b--;
    int a = b - 1;
    while (!miller_rabin(a)) a--;
    int c = t + 1;
    while (!miller_rabin(c)) c++;

    if (1ll * b * c <= 1ll * n) ans = 1ll * b * c;
    else ans = 1ll * a * b;

    printf("Case #%d: %lld\n", _, ans);
  }
  return 0;
}
