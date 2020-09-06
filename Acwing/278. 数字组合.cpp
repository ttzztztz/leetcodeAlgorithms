#include <iostream>
using namespace std;

long long dp[100005];
int number[105];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> number[i];

    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= number[i]; j--) {
            dp[j] += dp[j - number[i]];
        }
    }

    cout << dp[m];
    return  0;
}
