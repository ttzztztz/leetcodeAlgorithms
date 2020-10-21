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

const int MAX = 1e7+5;
int a[MAX];

int main() {
    int n, A, B, C;
    scanf("%d%d%d%d%d", &n, &A, &B, &C, a + 1);
    for (int i = 2; i <= n; i++)
        a[i] = ((long long) a[i - 1] * A + B) % 100000001;
    for (int i = 1; i <= n; i++)
        a[i] = a[i] % C + 1;

    typedef long double ld;
    ld ans = 0.0;
    ans += 1.0 * min(a[1], a[n]) / a[1] / a[n];
    for (int i = 2; i <= n; i++) {
        ans += 1.0 * min(a[i], a[i - 1]) / a[i] / a[i - 1];
    }
    printf("%.3Lf\n", ans);
    return 0;
}
