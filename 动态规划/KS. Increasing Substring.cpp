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
    ll ans = 0;
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> f(n, 1);
    for (int i = 1; i < n; i++) {
      if (s[i - 1] < s[i]) f[i] = f[i - 1] + 1;
      else f[i] = 1;
    }

    printf("Case #%d:", _);
    for (int i = 0; i < n; i++) {
      printf(" %d", f[i]);
    }
    printf("\n");
  }
  return 0;
}
