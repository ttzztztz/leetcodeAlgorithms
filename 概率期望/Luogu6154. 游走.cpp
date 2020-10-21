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

const int mod = 998244353;
typedef long long ll;

vector<vector<int>> edges;
vector<bool> visited;
vector<ll> f, g;

ll fastPow(ll a, int b) {
    ll ans = 1, base = a;
    while (b) {
        if (b & 1) ans = (ans * base) % mod;
        base = (base * base) % mod;

        b >>= 1;
    }
    return ans;
}

void dfs(int u) {
    if (visited[u]) return;
    visited[u] = true;

    g[u] = 1;
    for (int v : edges[u]) {
        dfs(v);

        f[u] = (f[u] + f[v] + g[v]) % mod;
        g[u] = (g[u] + g[v]) % mod;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    edges = vector<vector<int>>(n + 1, vector<int>{});
    visited = vector<bool>(n + 1, false);
    f = g = vector<ll>(n + 1, 0);

    vector<int> ind(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        edges[x].emplace_back(y);
        ind[y]++;
    }

    for (int i = 1; i <= n; i++) {
        if (ind[i] == 0) dfs(i);
    }

    ll a = 0, b = 0;
    for (int i = 1; i <= n; i++) {
        a = (a + f[i]) % mod;
        b = (b + g[i]) % mod;
    }

    printf("%lld\n", (a * fastPow(b, mod - 2)) % mod);
    return 0;
}
