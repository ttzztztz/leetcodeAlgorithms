#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 20, MAX_SUM = 180;
long long dp[MAX][2][MAX_SUM][MAX];
int digitLength = 0, digit[MAX];

long long dfs(int length, int isZero, int sum, int isSmall) {
    if (length == 0) {
        return (sum % 9 == 0) ? 0 : 1;
    }

    if (dp[length][isZero][sum][isSmall] != -1) {
        return dp[length][isZero][sum][isSmall];
    }

    long long answer = 0;
    for (int i = 0; i <= 8; i++) {
        if (!isSmall && i > digit[length]) {
            break;
        }

        answer += dfs(
            length - 1,
            isZero && i == 0,
            sum + i,
            isSmall || i < digit[length]
        );
    }
    return dp[length][isZero][sum][isSmall] = answer;
}

long long solve(long long x) {
    memset(dp, 0xff, sizeof(dp));
    memset(digit, 0, sizeof(digit));
    digitLength = 0;

    long long newX = x;
    while (newX) {
        digit[++digitLength] = newX % 10;
        newX /= 10;
    }
    return dfs(digitLength, 1, 0 ,0);
}

int main() {
    int testCase = 0;
    cin >> testCase;
    for (int _ = 1; _ <= testCase; _++) {
        long long left, right;
        cin >> left >> right;

        printf("Case #%d: %lld \n", _, solve(right) - solve(left - 1));
    }
    return 0;
}