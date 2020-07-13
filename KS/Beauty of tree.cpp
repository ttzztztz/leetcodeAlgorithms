#include "iostream"
#include "vector"
#include "unordered_set"
#include "unordered_map"
#include "set"
#include "map"
#include "algorithm"
#include "limits"
#include "cstring"
#include "queue"
#include "deque"

using namespace std;
vector<int> parent, f1, f2, path;
vector<vector<int>> edges;
int N, A, B;

void dfs(int u) {
    path.push_back(u);
    
    for (int v : edges[u]) {
        dfs(v);
    }
    
    f1[u]++, f2[u]++;
    const int sze = path.size();
    if (sze - A - 1 >= 0) f1[path[sze - A - 1]] += f1[u];
    if (sze - B - 1 >= 0) f2[path[sze - B - 1]] += f2[u];
    
    path.pop_back();
}

int main() {
    int T;
    cin >> T;

    for (int _ = 1; _ <= T; _++) {
        cin >> N >> A >> B;
        parent = f1 = f2 = vector<int>(N + 5, 0);
        edges = vector<vector<int>>(N + 5, vector<int>{});
        for (int i = 2; i <= N; i++) {
            cin >> parent[i];
            
            edges[parent[i]].push_back(i);
        }
        
        dfs(1);

        double answer = 0.0;
        for (int i = 1; i <= N; i++) {
            const double d1 = 1.0 * f1[i] / N, d2 = 1.0 * f2[i] / N;
            answer += d1 + d2 - d1 * d2;
        }
        printf("Case #%d: %lf\n", _, answer);
    }
    return 0;
}