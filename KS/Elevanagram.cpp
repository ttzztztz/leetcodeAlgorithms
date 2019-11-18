#include <iostream>
#include <cstring>

using namespace std;
long long digitNumber[15];
int dp[15][15][100];

void init() {
    memset(digitNumber, 0, sizeof(digitNumber));
    memset(dp, 0xff, sizeof(dp));
}

int dfs(int digit, long long state, long long restOdd) {
    if (digit == 10) {
        return 0 == ((state + 11) % 11) && restOdd == 0;
    }
    if (dp[digit][state][restOdd] != -1) {
        return dp[digit][state][restOdd];
    }

    int answer = 0;
    for (long long useOdd = 0; useOdd <= digitNumber[digit]; useOdd++) {
        if (useOdd > restOdd) {
            break;
        }

        answer |= dfs(digit + 1,
                      (state +  ((2 * useOdd - digitNumber[digit]) * digit) + 11) % 11,
                      restOdd - useOdd);
    }

    return dp[digit][state][restOdd] = answer;
}

int main() {
    int testCase = 0;
    cin >> testCase;
    for (int _ = 1; _ <= testCase; _++) {
        long long totalOdd = 0, totalDigit = 0;
        init();

        for (int i = 1; i <= 9; i++) {
            cin >> digitNumber[i];
            if (digitNumber[i] > 22) {
                if (digitNumber[i] % 2 == 1) {
                    digitNumber[i] = 21;
                } else {
                    digitNumber[i] = 22;
                }
            }

            totalDigit += digitNumber[i];
        }

        if (totalDigit % 2) {
            totalOdd = (totalDigit / 2) + 1;
        } else {
            totalOdd = totalDigit / 2;
        }

        long long answer = dfs(1, 0, totalOdd);
        printf("Case #%d: %s \n", _, answer ? "YES" : "NO");
    }
    return 0;
}