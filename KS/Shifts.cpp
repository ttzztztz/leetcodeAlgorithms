#include <iostream>
#include <vector>

using namespace std;

int main() {
    int testCase = 0;
    cin >> testCase;
    for (int _ = 1; _ <= testCase; _++) {
        long long answer = 0L;

        vector<long long> Ai, Bi;
        vector<long long> dp(1500000, 0);

        long long N, H;
        cin >> N >> H;
        for (int i = 0; i < N; i++) {
            int number = 0;
            cin >> number;
            Ai.push_back(number);
        }
        for (int i = 0; i < N; i++) {
            int number = 0;
            cin >> number;
            Bi.push_back(number);
        }

        const long long MAX_STATE = (1 << N) - 1;
        for (int stateA = 0; stateA <= MAX_STATE; stateA++) {
            long long sum = 0;
            for (int i = 0; i < N; i++) {
                if (stateA & (1 << i)) {
                    sum += Ai[i];
                }
            }
            if (sum >= H) {
                dp[stateA] = 1;
            }
        }

        for (int i = 0; i < N; i++) {
            for (int stateA = 0; stateA <= MAX_STATE; stateA++) {
                if (!(stateA & (1 << i))) {
                    dp[stateA] += dp[stateA | (1 << i)];
                }
            }
        }

        for (int stateB = 0; stateB <= MAX_STATE; stateB++) {
            long long temp = 0;
            int stateA = 0;

            for (int i = 0; i < N; i++) {
                if (stateB & (1 << i)) {
                    temp += Bi[i];
                } else {
                    stateA |= (1 << i);
                }
            }

            if (temp < H) {
                continue;
            }
            answer += dp[stateA];
        }

        printf("Case #%d: %lld \n", _, answer);
    }
    return 0;
}