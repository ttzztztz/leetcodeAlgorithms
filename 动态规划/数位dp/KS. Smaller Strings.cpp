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

const int mod = 1e9+7;
int n, k;
string s1, s2;
typedef long long ll;
ll f[100005][2];

ll dfs(int idx, int is_small) {
  if (idx == s1.size()) return is_small == 1;
  ll& val = f[idx][is_small];
  if (val != -1) return val;

  ll ans = 0;
  const char d = s1[idx];
  for (char ch = 'a'; ch <= 'a' + k - 1; ch++) {
    if (!is_small && ch > d) continue;

    ans = (ans + dfs(idx + 1, is_small || (ch < d))) % mod;
  }
  return val = ans;
}

int main() {
  // freopen("./in.txt", "r", stdin);
  int T;
  cin >> T;

  for (int _ = 1; _ <= T; _++) {
    string s;
    cin >> n >> k >> s;

    if (n % 2 == 1) {
      s1 = s.substr(0, n / 2);
      s2 = s.substr((n + 1) / 2);
      s1.push_back(s[n / 2]);
      s2.insert(s2.begin(), s[n / 2]);
    } else {
      s1 = s.substr(0, n / 2);
      s2 = s.substr((n + 1) / 2);
    }
    memset(f, 0xff, sizeof f);

    ll ans = dfs(0, 0);

    string s1r = s1;
    reverse(s1r.begin(), s1r.end());
    if (s1r < s2) {
      ans = (ans + 1 + mod) % mod;
    }
    printf("Case #%d: %lld\n", _, ans);
  }
  return 0;
}
