#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, V;
    cin >> N >> V;
    vector<int> v(N), w(N);
    for (int i = 0; i < N; i++) cin >> v[i] >> w[i];
    vector<int> f(V + 1, 0);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= V; j++) {
            if (j >= v[i]) f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }

    cout << f[V];
    return 0;
}