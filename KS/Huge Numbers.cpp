#include <iostream>

using namespace std;

long long fastPow(long long base, long long y, int P) {
    long long answer = 1;
    while (y) {
        if (y & 1) {
            answer *= base;
            answer %= P;
        }

        base *= base;
        base %= P;

        y >>= 1;
    }
    return answer;
}

int main() {
    int T = 0;
    cin >> T;
    for (int _ = 1; _ <= T; _++) {
        int A, N, P;
        cin >> A >> N >> P;
        long long answer = A % P;

        for (int i = 2; i <= N; i++) {
            answer *= fastPow(answer, i, P);
            answer %= P;
        }

        printf("Case #%d: %lld \n", _, answer);
    }
    return 0;
}