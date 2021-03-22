#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

int parent[1005];

void init() {
    memset(parent, 0, sizeof parent);
    for (int i = 0; i <= 1000; i++) {
        parent[i] = i;
    }
}

int find_parent(int u) {
    if (parent[u] == u) return u;
    else return parent[u] = find_parent(parent[u]);
}

void merge(int u, int v) {
    const int pu = find_parent(u), pv = find_parent(v);
    if (parent[pu] != pv) {
        parent[pu] = pv;
    }
}

int main() {
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; _++) {
        int n;
        cin >> n;

        vector<vector<int>> a(n, vector<int>(n, 0)), b(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> b[i][j];
        vector<int> r(n, 0), c(n, 0);
        for (int i = 0; i < n; i++) cin >> r[i];
        for (int i = 0; i < n; i++) cin >> c[i];

        ll ttl = 0;
        typedef tuple<int, int, int> State;
        vector<State> all;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (b[i][j]) {
                    ttl += b[i][j];
                    all.emplace_back(b[i][j], i, j);
                }
            }
        }
        sort(all.rbegin(), all.rend());
        ll mx = 0;
        init();
        for (auto&[w, u, v] : all) {
            const int idxu = u, idxv = 501 + v;
            if (find_parent(idxu) != find_parent(idxv)) {
                merge(idxu, idxv);
                mx += w;
            }
        }

        ll ans = ttl - mx;
        printf("Case #%d: %lld\n", _, ans);
    }
    return 0;
}

