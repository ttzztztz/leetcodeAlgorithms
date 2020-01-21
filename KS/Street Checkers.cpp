#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
vector<bool> isPrime1, isPrime2;

void init(long long L, long long R, vector<bool>& isPrime) {
    vector<bool> helper = vector<bool>(sqrt(R) + 5, true);
    isPrime = vector<bool>(R - L + 5, true);

    for (long long i = 2; i * i <= R; i++) {
        if (helper[i]) {
            for (long long j = 2 * i; j * j <= R; j += i) {
                helper[j] = false;
            }

            for (long long j = max(2ll, (L + i - 1) / i) * i; j <= R; j += i) {
                isPrime[j - L] = false;
            }
        }
    }
}

int count2(long long &x) {
    int answer = 0;
    while (x % 2 == 0) {
        answer++;
        x >>= 1;
    }
    return answer;
}

int main() {
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; _++) {
        long long L, R;
        cin >> L >> R;
        init(L, R, isPrime1);
        init(L / 4, R / 4, isPrime2);

        long long answer = 0;
        for (long long i = L; i <= R; i++) {
            long long temp = i;
            int count = count2(temp);

            if ((count == 3 && temp == 1) || (count == 2 && isPrime2[temp - (L / 4)]) ||
                (count == 1 && temp % 2 == 1) || (count == 0 && isPrime1[temp - L])) {
                answer++;
            }
        }
        printf("Case #%d: %lld\n", _, answer);
    }

    return 0;
}