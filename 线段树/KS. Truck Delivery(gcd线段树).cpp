#include <iostream>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

typedef tuple<int, ll, ll> State;
typedef pair<ll, int> Query;
vector<vector<State>> edges;
vector<ll> ans;
unordered_map<int, vector<Query>> queries;

ll __gcd(ll a, ll b) {
  if (b == 0)
    return a;
  else
    return __gcd(b, a % b);
}

class SegmentTreeNode {
 public:
  int left, right;
  long long gcd;

  SegmentTreeNode() : left(0), right(0), gcd(0){};
};

const int inf = 2e5 + 1;
SegmentTreeNode treeNode[(inf + 5) * 4];

int L(int u) { return (u << 1); }

int R(int u) { return (u << 1) + 1; }

void pushDown(int u) {}

void pushUp(int u) {
  treeNode[u].gcd = __gcd(treeNode[L(u)].gcd, treeNode[R(u)].gcd);
}

void build(int u, int left, int right) {
  treeNode[u].left = left;
  treeNode[u].right = right;
  treeNode[u].gcd = 0;

  if (left == right) {
    return;
  }

  int middle = (left + right) >> 1;
  build(L(u), left, middle);
  build(R(u), middle + 1, right);
  pushUp(u);
}

void update(int u, int left, int right, long long val, bool force) {
  if (left <= treeNode[u].left && treeNode[u].right <= right) {
    if (force) {
      treeNode[u].gcd = val;
    } else {
      treeNode[u].gcd = __gcd(val, treeNode[u].gcd);
    }
    return;
  }

  pushDown(u);
  int middle = (treeNode[u].left + treeNode[u].right) >> 1;
  if (left <= middle) {
    update(L(u), left, right, val, force);
  }
  if (middle < right) {
    update(R(u), left, right, val, force);
  }
  pushUp(u);
}

long long query(int u, int left, int right) {
  if (left <= treeNode[u].left && treeNode[u].right <= right) {
    return treeNode[u].gcd;
  }

  long long answer = 0;
  pushDown(u);
  int middle = (treeNode[u].left + treeNode[u].right) >> 1;
  if (left <= middle) {
    answer = __gcd(answer, query(L(u), left, right));
  }
  if (middle < right) {
    answer = __gcd(answer, query(R(u), left, right));
  }
  return answer;
}

ll dfs(int u, int parent) {
  if (queries.count(u)) {
    for (auto& [w, idx] : queries[u]) {
      ans[idx] = query(1, 1, w);
    }
  }

  for (auto [v, l, a] : edges[u]) {
    if (v == parent) continue;

    const int t = query(1, l, l);
    update(1, l, l, a, false);
    dfs(v, u);
    update(1, l, l, t, true);
  }
  return -1;
}

int main() {
  //  freopen("./in.txt", "r", stdin);
  int T;
  cin >> T;
  for (int _ = 1; _ <= T; _++) {
    int n, q;
    cin >> n >> q;
    edges = vector<vector<State>>(n + 1, vector<State>{});
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      ll l, a;
      cin >> u >> v >> l >> a;
      edges[u].emplace_back(v, l, a);
      edges[v].emplace_back(u, l, a);
    }

    queries.clear();
    ans = vector<ll>(q, 0);
    build(1, 1, inf);

    for (int i = 0; i < q; i++) {
      int c;
      ll w;
      cin >> c >> w;
      queries[c].emplace_back(w, i);
    }

    dfs(1, -1);
    printf("Case #%d:", _);
    for (int i = 0; i < q; i++) {
      printf(" %lld", ans[i]);
    }
    printf("\n");
  }
  return 0;
}
