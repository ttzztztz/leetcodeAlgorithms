#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1000000007;

long long fastPowMod(long long x, long long y) {
    long long answer = 1L, pow = x;

    while (y) {
        if (y & 1) {
            answer = (pow * answer) % MOD;
        }

        pow = (pow * pow) % MOD;
        y >>= 1;
    }

    return answer % MOD;
}

long long getReversed(long long x) {
    return fastPowMod(x, MOD - 2);
}

int main() {
    int testCase = 0;
    cin >> testCase;
    for (int _ = 1; _ <= testCase; _++) {
        // <-- construct data & input
        long long answer = 0L, C, D, E1, E2, F;
        int N, K;
        cin >> N >> K;
        vector<long long> X(N + 5, 0);
        vector<long long> Y(N + 5, 0);
        vector<long long> A(N + 5, 0);
        cin >> X[1] >> Y[1] >> C >> D >> E1 >> E2 >> F;

        for (int i = 2; i <= N; i++) {
            X[i] = ((C * X[i - 1]) + (D * Y[i - 1]) + E1) % F;
            Y[i] = ((D * X[i - 1]) + (C * Y[i - 1]) + E2) % F;
        }

        for (int i = 1; i <= N; i++) {
            A[i] = (X[i] + Y[i]) % F;
        }
        // <-- solve
        long long lastAnswer = 0;
        for (int i = 1; i <= N; i++) {
            if (i == 1) {
                lastAnswer = K;
            } else {
                lastAnswer = (lastAnswer +
                              (i * (
                                      ((fastPowMod(i, K) - 1) * getReversed(i - 1)) % MOD
                              )
                               % MOD
                              )
                              % MOD) % MOD;
            }

            answer = (answer + (
                                       (A[i] * (N - i + 1)) % MOD *
                                       lastAnswer % MOD
                               ) % MOD) % MOD;
        }
        // <-- output
        printf("Case #%d: %lld \n", _, answer);
    }
    return 0;
}