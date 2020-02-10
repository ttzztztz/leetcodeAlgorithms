#include <iostream>
#include <algorithm>

using namespace std;

int N;
int A[3005], B[3005];
int dp[3005][3005];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 1; i <= N; i++) cin >> B[i];

    int answer = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = dp[i - 1][j];

            int _max = 1;
            if (A[i] == B[j]) {
                for (int k = 1; k <= j; k++) {
                    if (B[j] > B[k]) {
                        _max = max(_max, 1 + dp[i - 1][k]);
                    }
                }
                dp[i][j] = max(dp[i][j], _max);
            }
        }
    }

    for (int j = 1; j <= N; j++) {
        answer = max(answer, dp[N][j]);
    }
    cout << answer << endl;
    return 0;
}
