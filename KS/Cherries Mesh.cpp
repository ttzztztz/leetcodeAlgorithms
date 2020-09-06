#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

void init(int N) {
    parent.clear();
    parent.resize(N + 5);
    for (int i = 0; i <= N; i++) {
        parent[i] = i;
    }
}

int findParent(int u) {
    if (parent[u] == u) {
        return parent[u];
    } else {
        return parent[u] = findParent(parent[u]);
    }
}

void merge(int u, int v) {
    const int parentU = findParent(u), parentV = findParent(v);
    if (parentU != parentV) {
        parent[parentU] = parentV;
    }
}

int main() {
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; _++) {
        long long answer = 0;
        int N, M;
        cin >> N >> M;
        init(N);
        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;

            const int parentU = findParent(u), parentV = findParent(v);
            if (parentU != parentV) {
                merge(u, v);
                answer++;
            }
        }

        answer += (N - 1 - answer) * 2;
        printf("Case #%d: %lld \n", _, answer);
    }
    return 0;
}