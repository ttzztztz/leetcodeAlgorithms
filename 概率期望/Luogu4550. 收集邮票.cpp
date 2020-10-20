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

int main() {
    int N;
    cin >> N;
    vector<double> f(N + 1, 0), g(N + 1, 0);
    for (int i = N - 1; i >= 0; i--) {
        f[i] = 1.0 * N / (N - i) + f[i + 1];
        g[i] = 1.0 * i / (N - i) * f[i] + 1.0 * N / (N - i) + f[i + 1] + g[i + 1];
    }
    printf("%.2f\n", g[0]);
    return 0;
}
