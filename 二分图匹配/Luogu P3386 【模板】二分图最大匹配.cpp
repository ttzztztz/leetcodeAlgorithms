#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> edges;
vector<int> parent;
vector<bool> visited;

bool match(int u) {
  for (int v : edges[u]) {
    if (!visited[v]) {
      visited[v] = true;
      if (parent[v] == 0 || match(parent[v])) {
        parent[v] = u;
        return true;
      }
    }
  }
  return false;
}

int main() {
  // freopen("./in.txt", "r", stdin);
  int n, m, e;
  cin >> n >> m >> e;
  edges = vector<vector<int>>(n + 1);

  for (int i = 0; i < e; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
  }

  int ans = 0;
  parent = vector<int>(m + 1, 0);
  for (int i = 1; i <= n; i++) {
    visited = vector<bool>(m + 1, false);
    if (match(i)) ans++;
  }
  cout << ans << endl;
  return 0;
}
