#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 1000000007, MAX = 300005;

long long memoFact[MAX];

long long pow(long long x, int y) {
    long long answer = 1;

    while (y) {
        if (y & 1) {
            answer = answer * x % MOD;
        }

        x = x * x % MOD;
        y >>= 1;
    }

    return answer % MOD;
}

void initFact() {
    memoFact[0] = memoFact[1] = 1;
    for (long long i = 2; i <= MAX; i++) {
        memoFact[i] = (memoFact[i - 1] * i) % MOD;
    }
}

long long getInverse(long long x) {
    return pow(x, MOD - 2) % MOD;
}

long long calcC(long long N, long long M) {
    if (N == M || M == 0) {
        return 1;
    }
    return (memoFact[N] * getInverse(memoFact[N - M]) % MOD) * getInverse(memoFact[M]) % MOD;
}

int main() {
    initFact();

    int testCase = 0;
    cin >> testCase;
    for (int _ = 1; _ <= testCase; _++) {
        long long answer = 0;
        int N, M;
        cin >> N >> M;

        for (int i = 0; i <= M; i++) {
            long long delta = ((calcC(M, i) * pow(2, i) % MOD) * memoFact[2 * N - i] % MOD) % MOD;
            if (i & 1) { // should minus
                answer = (answer - delta + MOD) % MOD;
            } else { // should increment
                answer = (answer + delta + MOD) % MOD;
            }
        }

        printf("Case #%d: %lld\n", _, answer % MOD);
    }
    return 0;
}
