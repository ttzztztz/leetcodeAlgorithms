#include <iostream>
using namespace std;

const int N = 4005;
const long long MOD = 2147483648;
long long dp[N];

int main() {
    int n;
    cin >> n;

    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            dp[j] += dp[j - i];
            dp[j] %= MOD;
        }
    }

    cout << dp[n] - 1;
    return  0;
}
