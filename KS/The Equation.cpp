#include <iostream>
#include <vector>

using namespace std;
const int MAXN = 52;

int main() {
    int testCase = 0;
    cin >> testCase;
    for (int _ = 1; _ <= testCase; _++) {
        long long N, M;
        cin >> N >> M;
        vector<long long> Ai;
        vector<long long> digit_1_count(72, 0), digit_0_count(72, 0);

        for (int i = 0; i < N; i++) {
            long long number = 0;
            cin >> number;
            Ai.push_back(number);

            for (int i = 0; i <= MAXN; i++) {
                if (number & 1) {
                    digit_1_count[i]++;
                } else {
                    digit_0_count[i]++;
                }
                number >>= 1;
            }
        }

        vector<long long> suffixSum(72, 0), number1(72, 0), number0(72, 0);
        for (int i = 0; i <= MAXN; i++) {
            number1[i] = 1ll * digit_0_count[i] * (1ll << i);
            number0[i] = 1ll * digit_1_count[i] * (1ll << i);
        }

        suffixSum[0] = std::min(number0[0], number1[0]);
        for (int i = 1; i <= MAXN; i++) {
            suffixSum[i] = suffixSum[i - 1] + std::min(number0[i], number1[i]);
        }

        long long currentSum = 0, K = 0;
        for (int i = MAXN; i >= 0 && currentSum <= M; i--) {
            long long lowerSum = (i == 0) ? 0 : suffixSum[i - 1];
            if (currentSum + lowerSum + number1[i] <= M) {
                K |= 1ll << i;
                currentSum += number1[i];
            } else {
                currentSum += number0[i];
            }
        }

        if (currentSum > M) {
            printf("Case #%d: -1 \n", _);
        } else {
            printf("Case #%d: %lld \n", _, K);
        }
    }
    return 0;
}