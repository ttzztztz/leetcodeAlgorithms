#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

int main() {
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; _++) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        ll ans = 0;
        ll t = 0;
        for (int i = 0; i < (n / 2); i++) {
            t += s[i] != s[n - i - 1];
        }
        ans = abs(k - t);
        printf("Case #%d: %lld\n", _, ans);
    }
    return 0;
}

